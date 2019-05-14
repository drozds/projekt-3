#include <iostream>
#include <string>
#include <cmath>
#include "test.h"

using namespace std;

int main() {
    Test *test = new Test();
    test->testLiczba();
    test->testStack();
    test->testCalc();
    delete test;
}