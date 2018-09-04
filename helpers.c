// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // TODO
    int numerator = fraction[0] - '0';
    int denominator = fraction[2] - '0';
    int duration = 8 * numerator / denominator;
    return duration;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // TODO
    double freq;
    //Checking for the note
    switch (note[0])
    {
        case 'C':
            freq = 440.0 / pow(2.0, (9.0 / 12.0));
            break;
        case 'D':
            freq = 440.0 / pow(2.0, (7.0 / 12.0));
            break;
        case 'E':
            freq = 440.0 / pow(2.0, (5.0 / 12.0));
            break;
        case 'F':
            freq = 440.0 / pow(2.0, (4.0 / 12.0));;
            break;
        case 'G':
            freq = 440.0 / pow(2.0, (2.0 / 12.0));
            break;
        case 'A':
            freq = 440.0;
            break;
        case 'B':
            freq = 440.0 * pow(2.0, (2.0 / 12.0));
            break;
    }
    //Checking for flat or sharp
    if (note[1] == '#')
    {
        freq *= pow(2.0, (1.0 / 12.0));
    }
    if (note[1] == 'b')
    {
        freq /= pow(2.0, (1.0 / 12.0));
    }
    //Cheking for the octave
    int octave = note[strlen(note) - 1] - '0';

    if (octave > 4)
    {
        freq *= pow(2.0, (octave - 4));
    }
    if (octave < 4)
    {
        freq /= pow(2.0, (4 - octave));
    }
    //Return result
    return round(freq);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // TODO
    if (strlen(s) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
