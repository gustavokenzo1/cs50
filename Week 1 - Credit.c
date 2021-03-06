#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long number;
     
    //Asks user for a non-negative credit card number
    do
    {
        number = get_long("Credit Card Number: ");
    }
    while (number < 0);
     
    //Counts how many digits that number has
    int digits = 0;
    long d = number;
     
    while (d > 0)
    {
        d = d / 10;
        digits++;
    }
     
    //Invalidates obviously wrong numbers
    if (digits != 13 && digits != 15 && digits != 16)
    {
        printf("INVALID\n");
    }
     
    else 
    {
        //Luhn's algorithm or something like that
        long cc = number;
        int part1 = 0;
        int digit1, digit2, separate1, separate2, total;
        int part2 = 0;
     
     
        do //Number for guidance: 4003600000000014
        {
            digit1 = cc % 10; //Divides by 10 and gets the remainder
            cc /= 10; //Divides by 10 and discards last digit
            part1 = part1 + digit1; //Sums that digit with the previous remainders 
            digit2 = cc % 10; //Divides by 10 and gets the next digit
            cc /= 10; //Discards that digit
            digit2 = digit2 * 2; //Multiplies that digit by 2
            separate1 = digit2 % 10; //If that digit is greater than 9 it will separate it into 2 digits
            separate2 = digit2 / 10; //Picks that other digit
            part2 = part2 + separate1 + separate2; //Sums everything
        }
        while (cc > 0);
     
        total = part1 + part2;
     
        //Sum check, last digit must be 0
        if (total % 10 != 0)
        {
            printf("INVALID\n");
        }
     
        if (total % 10 == 0)
        {
            //AMEX: 34 or 37 | 15 digits
            //MASTERCARD: 51, 52, 53, 54 or 55 | 16 digits
            //VISA: 4 | 13 or 16 digits
     
            int first_digits;
            long c = number;
     
            //Divides credit card number until it gets the first numbers
            do
            {
                c /= 10;
                first_digits = c;
            }
            while (c > 55);
     
            int visa = first_digits / 10;
     
            if ((digits == 13 && visa == 4) || (digits == 16 && visa == 4))
            {
                printf("VISA\n");
            }
     
            else if ((digits == 15 && first_digits == 34) || (digits == 15 && first_digits == 37))
            {
                printf("AMEX\n");
            }
     
            else if ((digits == 16 && first_digits == 51) || (digits = 16 && first_digits == 52) || (digits = 16 && first_digits == 53)
                     || (digits = 16 && first_digits == 54) || (digits = 16 && first_digits == 55))
            {
                printf("MASTERCARD\n");
            }
     
            else
            {
                printf("INVALID\n");
            }
        }
    }
}
