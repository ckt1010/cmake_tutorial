#include <math.h>
#include <iostream>
#include "step3.h"

double mysqrt(double in) {
    std::cout << "mysqrt enter" << std::endl;
#if defined(HAVE_LOG) && defined(HAVE_EXP)
    double result = exp(log(in) * 0.5);
    std::cout << "Computing sqrt of " << in << " to be " << result << " using log and exp"
              << std::endl;
#else
    double result = sqrt(in);
#endif
    return result;
}