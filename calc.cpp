#include <iostream>
#include "calc.h"
#include "stack.h"

using namespace std;

bool Calc::isOperator(const string& input) {
    static const string operators ="-+*/";
    if (input.length() == 1) // right size to be an operator.
    {
        return operators.find_first_of(input[0]) != string::npos;// look in the operator string for the first (and only) character in input
    }
    return false;
}

int Calc::performOperation(const string& input, stack<double>& calcStack) {
    double firstOperand;
    double secondOperand;
    double result;
    

    if( calcStack.size() < 2 )
        {
            cout << "Error: too many operators" << endl;
            return 1;
        }


    secondOperand = calcStack.top();
    calcStack.pop();


    firstOperand = calcStack.top();
    calcStack.pop();

    switch (input[0])
    {
        case '-':
            result = firstOperand - secondOperand;
            break;
        case '+':
            result = firstOperand + secondOperand;
            break;
        case '*':
            result = firstOperand * secondOperand;
            break;
        case '/':
            if (secondOperand == 0)
            {
                cout << "Error: Division by 0.\n";
                return -1;
            }
            result = firstOperand / secondOperand;
            break;
    }

    cout << "Output\n";
    cout << result << endl;
    calcStack.push(result);

    return 0;
}