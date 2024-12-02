#ifndef CALCULATION_H
#define CALCULATION_H
#include "complex.h"
double calculate_resonant_frequency(double L, double C)
{
    return 1.0 / (2.0 * M_PI * sqrt(L* C));
}

#endif
