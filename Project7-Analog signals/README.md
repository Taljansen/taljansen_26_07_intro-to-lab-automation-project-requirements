# Project7 - Analog!

1. Understand the difference between analog and digital signals
1. Learn to use a voltmeter and scope
1. Measure analog signals
1. Understand PWM and when to use it
1. Learn about MD_PWM package
1. Learn about servo motors
1. Understand arduino signal capabilities

## Adding a dimmer functionality to the LED

The purpose of this project is to dim and increase the led light using the rotary button.

- rotary is A0 in Arduino. connect gnd (in arduino) first to orange with stripe (in ADALM) and then A0 to orange. ✓
- Use voltmeter in Scopy to see range of values when turning the rotary. ✓ --> range is 0 V to 5.028 V
- create an Arduino file that reads the values from the rotary and prints them out. What is the range of the values? ✓

all the way to the right: 0
all the way to the left: 1023

- pin 4 (grove LED) is not supported for PWM. Install package MD_PWM, and set pin 4 to be PWM using the package documentation. ✓
- Using the rotary value, update the PWM value. Note the range of values that can be used according to package documentation. Change your code accordingly. ✓
- test your code. ✓
- View in scope: Connect Analog 2 (dark blue) to pin 4 in arduino (LED output). Play with the times and triggers until you see the PWM change when turning the rotary.  What is the duty cycle? ✓

The duty cycle is the percentage of each PWM period during which the pin is held at 5 V. It is controlled by the rotary potentiometer. Measured on the scope (Analog 2 on pin 4), the period stayed at 20.733 ms and the frequency at 48.23 Hz for every knob position, only the width of the HIGH pulse changed.

Rotary value	+Duty	Mean voltage
~0	            12.93%	  284 mV
512	            50.02%	2.393 V
~1023	        97.27%	4.876 V


- View in voltmeter - stop scope first. See the average voltage change. What does it mean?

The voltmeter shows the average voltage on pin 4. It rises from 0 V to ~5 V as the duty cycle goes from 0% to 100%. Average = 5 V × duty cycle. This is the point of PWM: the pin is only ever at 0 V or 5 V That average is the analog output the Arduino cannot produce directly.

- what happens when using 30Hz instead of 50Hz for the PWM?

At 30 Hz the period grows from 20.7 ms to about 33 ms. The duty cycle range and average voltage are unchanged. What changes is visible flicker. 30 Hz is below the rate at which the eye blends the pulses together, so the LED visibly blinks instead of looking dim. Frequency must be high enough to hide the switching; duty cycle sets the brightness.

- paste a screenshot of the oscilloscope where both the rotary potentiometer signal and the PWM signal on the led are seen.

![PWM signal on pin 4 and rotary output on A0](images/pwm_rotary_both_signals.png)

## Use PWM to control a servo motor

Documentation on Servo [here](https://wiki.seeedstudio.com/Grove-Servo/)

- connect analog 2 in adalm (dark blue) to digital 7 in arduino ✓
- install Servo package if not already installed ✓
- initialize Servo package with pin 7
- first look at the PWM signal in adalm. What frequency is the Servo package using?
- connect to servo using D7 breakout (there is only one way to do this, ground - black wire - close to the grove led). 
- turn rotary to turn the servo
- How does the range of the duty cycle in servo motor compare to the range of the duty cycle we used in the LED? Use the scope.
- is the range of angles in our servo the same as the range of the angles in the Servo package? change the range of values to the servo accordingly.
- Paste a screenshot of the scope showing the maximum duty cycle of the servo (the maximum angle the servo succeeded rotating without problems)

## Exercises
 - Comparison of AI changes if any:
- commit and push both .ino files and their folders to your repository




