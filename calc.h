#ifndef CALC_H
#define CALC_H

#include <iostream>
#include <stack>
#include <string>
#include <sstream> 
#include<iomanip>

using namespace std;

class Calc {
    public:
    bool isOperator(const string& input);
    int performOperation(const string& input, stack<double>& calcStack);
};

#endif