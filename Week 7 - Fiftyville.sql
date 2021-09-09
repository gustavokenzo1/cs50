-- Keep a log of any SQL queries you execute as you solve the mystery.
-- I'm not going to put every ".schema ..." here.

-- As per CS50's reccomendation, let's start by analyzing the crime scene reports

SELECT description FROM crime_scene_reports WHERE year = 2020 AND month = 7 AND day = 28;

-- Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse. Interviews were 
-- conducted today with three witnesses who were present at the time — each of their interview
-- transcripts mentions the courthouse

-- First of all, what do you mean someone stole the duck? It's right here on top right corner...
-- I swear it wasn't me.

-- 10:15 am
-- Chamberlin Street courthouse 
-- 3 witnessess

-- Let's look at their interviews
SELECT transcript FROM interviews WHERE day = 28 AND month = 7 AND year = 2020;

-- Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking
-- lot and drive away. If you have security footage from the courthouse parking lot, you might want
-- to look for cars that left the parking lot in that time frame.

-- I don't know the thief's name, but it was someone I recognized. Earlier this morning, before 
-- I arrived at the courthouse, I was walking by the ATM on Fifer Street and saw the thief there
-- withdrawing some money.

-- As the thief was leaving the courthouse, they called someone who talked to them for less than
-- a minute. In the call, I heard the thief say that they were planning to take the earliest flight
-- out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to
-- purchase the flight ticket.

-- Each interview says something different, so we should treat them as equally important and
-- analyze the hints 1 by 1.

-- 1st interview:
-- 10:15 <= t <= 10:25, where t = time of robbery
-- Left courthouse's parking lot 
-- Let's take a look at who left between that timeframe

SELECT name FROM people WHERE license_plate IN (SELECT license_plate FROM courthouse_security_logs
WHERE day = 28 AND month = 7 AND year = 2020 AND activity = 'exit' AND hour = 10 AND minute <= 25);

-- First suspects:
-- Patrick, Amber, Elizabeth, Roger, Danielle, Russell, Evelyn, Ernest

-- 2nd interview:
-- Thief withdrew money from an ATM at Fifer Street
-- Before 10:15
-- Let's take a look at who withdrew money

SELECT name FROM people WHERE id IN
(SELECT person_id FROM bank_accounts WHERE account_number IN
(SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND year = 2020
AND atm_location = 'Fifer Street' AND transaction_type = 'withdraw'));

-- More suspects:
-- Bobby, Elizabeth, Victoria, Madison, Roy, Danielle, Russell, Ernest

-- 3rd interview:
-- Called someone for less than a minute
-- Earliest flight out of Fiftyville on the 29th
-- Thief asked person to purchase a ticket

SELECT name FROM people JOIN passengers ON people.passport_number = passengers.passport_number
WHERE flight_id = (SELECT id FROM flights WHERE day = 29 AND month = 7 AND year = 2020 
ORDER BY hour, minute LIMIT 1);

-- More suspects:
-- Doris, Roger, Ernest, Edward, Evelyn, Madison, Bobby, Danielle

-- Since we are out of interviews, we can find the intersections:
-- Main suspects: Danielle and Ernest.

-- In my opinion, I think that when CS50 staff were creating this problem, they were creating the
-- tables in the order they think we should follow, since they also followed a line of thought that
-- probably lead to this order of tables, so we should probably use phone_calls now:

SELECT name FROM people JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE day = 28 AND month = 7 AND year = 2020 AND duration < 60;

-- Suspect is...:
-- Roger, Evelyn, Ernest, Evelyn, Madison, Russell, Kimberly, Bobby, Victoria

-- Bingo! Ernest, you've won the Oscars for the most heartless thief ever, you may claim your trophie
-- in your prison cell, along with...

-- Let's find who Ernest called:
SELECT name FROM people JOIN phone_calls ON people.phone_number = phone_calls.receiver
WHERE day = 28 AND month = 7 AND year = 2020 AND duration < 60 
AND caller = (SELECT phone_number FROM people WHERE name = "Ernest");

-- Yup, Berthold and Ernest, gotcha.
-- Now let's see where Ernest was going:

SELECT city FROM airports WHERE id IN (SELECT destination_airport_id FROM flights WHERE
day = 29 AND month = 7 AND year = 2020 ORDER BY hour, minute LIMIT 1);

-- No London for you, lol.
