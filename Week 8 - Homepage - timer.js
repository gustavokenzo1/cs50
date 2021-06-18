"use strict"

var min = 0;
var seg = 0;
var mil = 0;

var tempo = 10;
var cron;

function start() {
  cron = setInterval(() => { timer();  }, tempo);
}

function timer() {
  mil++;

  if (mil == 100) {
    mil = 0;
    seg++;

    if (seg == 60) {
      seg = 0;
      min++;
    }
  }
  var format = min + ':' + (seg < 10 ? '0' + seg : seg) + '.' + (mil < 10 ? '0' + mil : mil);
  document.getElementById('display').innerText = format;
}

function pause() {
  clearInterval(cron);
}

function reset() {
  min = 0;
  seg = 0;
  mil = 0;
  clearInterval(cron);
}
