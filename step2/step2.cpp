#include "step2.h"
#ifdef USE_MYMATH
#include "MathFunctions.h"
#else
#include <math.h>
#endif
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    const double inputValue = stod(argv[1]);
    #ifdef USE_MYMATH
    cout << "USE_MYMATH\n";
    const double outputValue = mysqrt(inputValue);
    #else
    cout << "not USE_MYMATH\n";
    const double outputValue = sqrt(inputValue);
    #endif
    cout << "Version " << STEP2_VERSION_MAJOR << "." << STEP2_VERSION_MINOR << endl;
    cout << "InputValue: " << inputValue << " OutputValue: " << outputValue << endl;
    return 0;
}