# Password-activated-door

This project allows you to open the door of your home by entering your password.


## Components used in this project:

(1) ATmega 32.

(2) LCD 40*2.

(3) Keypad 4*4.

(4) Servo Motor.

(5) LED.

(6) Buzzer


## Features of the project:

(1) Automatically opening the door using password.

(2) Secure as if you entered the password 3 times wrong, the door will be closed permanently.

N.B: Before getting into the overview of the code, the password is set initially to "12345".


## Overview of the code:

First of all, a welcome message will be appeared on LCD 

Secondly, Enter the password.

The code will ask you to enter the password (which is "12345"). If the password is right, the Servo Motor will rotate +90 degree which means that the door is opened. However, if the password is wrong, the door won't open (and absolutely the Servo Motor won't rotate).


## Short notes about entering the password:

If you entered the password three times wrong, the LED and Buzzer will turn on and it will block you from re-entering the password then makes you able to try again.


## About the attached files:

(1) This code is implemented on Eclipse IDE. So, it is highly recommended to download it and begin using my code.

(2)A proteus simulation is also attached.


