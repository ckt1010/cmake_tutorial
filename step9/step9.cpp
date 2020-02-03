#include "step9.h"
#include "MathFunctions.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    const double inputValue = stod(argv[1]);
    const double outputValue = mathfunctions::sqrt(inputValue);
    cout << "Version " << STEP9_VERSION_MAJOR << "." << STEP9_VERSION_MINOR << endl;
    cout << "InputValue: " << inputValue << " OutputValue: " << outputValue << endl;
    return 0;
}