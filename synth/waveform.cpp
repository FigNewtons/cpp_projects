/*             Waveform Generator Template
				

Constants
----------
R = sample rate (measured in Hertz, or samples per second)
P = frequency of the pitch (also measured in Hertz)
B = bit-value
F = bit depth ( sample rate / bit-value)
V = volume (amplitude) 

t = time (seconds)
temp = output value of the wave function


Notes
----------
The sample rate is how often the computer takes the 
value of the wave function f(t). It is the vertical snapshot
of the analog sound. The bit depth determines the detail of 
the dymanic range by the bit-value. It is the horizontal 
snapshot of the analog sound.

For 8-bit playback, use:
R = 8000   (8k Hertz)
B = 256    (2^8)

For 16-bit playback, use:
R = 16000  (16k Hertz)
B = 65536  (2^16)

- iostream allows output (duh)

- cmath lets you use the sin function and use M_PI as the constant for pi

- stdint.h lets you declare unsigned 8-bit or 16-bit values for playback
  (uint8_t or uint16_t)


To compile and run the program, type the following in terminal:

> make waveform   OR  >g++ waveform.cpp -o waveform
> ./waveform | aplay

Frequency Formula
------------------
f(n) = 2^((n-49)/12) x 440 Hz 

Where n = piano key number (out of 88)

A4 is the 49th key and has the frequency of 440Hz


Explanation of generation wave shapes
--------------------------------------

1. Sine wave 

This is the most basic form of a sine wave:
f(t) = A * sin(2pi * f* t + p)

where A = amplitude, f = frequency, t = time, and p = phase shift

To create a pure sine wave sound, we must modify the above formula
to fit the pitch, sample rate, and volume we have provided. We must 
also shift the sine wave up 1 so that f(t) > 0 when t = 0. The shift
along with the sin are then multiplied by the volume to get the 
following:

f(t) = V * (sin(2pi * P *t / R) + 1)

2. Saw Wave

A saw wave is simply a piecewise linear function. The form for one
note is:

f(t) = t / P * F


Credits to the user nobar of stackoverflow.net for the sample code
that inspired this program.
*/





#include <iostream>
#include <cmath>
#include <stdint.h>

using namespace std;

int main()
{
    const double R = 8000; //sample rate (samples per second)
    const double P = 261.625565; // frequency of middle C (Hertz)
    const double F = R / 256; // byte beat frequency of 1*t due to 8-bit truncation
    const double V = 127; // Volume constant

	for (int t=0; ; t++)
	{
		uint8_t temp = (sin(t*2*M_PI/R *P)+1)*V; //pure Middle C sine wave
    //	uint8_t temp = t/F*P; //middle C saw wave (bytebeat style)
	//	uint8_t temp = (t*5 & t>>7)|(t*3 & t>>10); // viznut bytebeat composition
		cout << temp;
	}

	return 0;
}

 


