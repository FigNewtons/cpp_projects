#include <iostream>
#include <string>
#include <cmath> 
#include <stdint.h>

using namespace std;

// Wave constants
const double R = 8000; //sample rate (samples per second)
const double F = R / 256; // byte beat frequency of 1*t due to 8-bit truncation
const double V = 127; // Volume constant (based on personal preference) 

// Standard tuning note
const double A4_FREQ = 440.000000;
const double A4_KEY = 49.0000000;

// Scale interval patterns (1 = half step, 2 = whole step, etc.)
int diatonic[7] = {2,2,1,2,2,2,1};
int harm_minor[7] = {2,1,2,2,1,3,1};
int mel_minor[7] = {2,1,2,2,2,2,1};
int pentatonic[5] = {2,2,3,2,3};

// Function prototypes
int scale(int, int, int[], int);
double calculate_freq(int);
void playback(double);



// Main starts here
int main()
{
	scale(1, 40, pentatonic, sizeof(pentatonic)/sizeof(*pentatonic));
	return 0;
}



// This iterates through a given scale (based on the interval array
int scale(int octaves, int tonic, int interval[], int array_size)
{
	for(int i=0; i <= array_size; i++)
	{
		playback(calculate_freq(tonic));
		tonic += interval[i];
	}

	return 0;
}


// Calculates the frequency of each note as it is called
double calculate_freq(int key)
{
    double exp = (key - A4_KEY)/ 12;
    double freq = pow(2.000000, exp) * A4_FREQ;
	return freq;
}


// This plays back each note as it is called
void playback(double f)
{
    for (int t=0; t < 10000; t++)
	{
		uint8_t temp = (sin(t*2*M_PI/R *f)+1)*V; //pure sine wave  
		cout << temp;
	}
}

/*
To do list:
	1. Add chords 
	2. Add octaves 
	3. Allow for descending scales
*/

