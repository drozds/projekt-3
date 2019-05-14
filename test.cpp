#include <iostream>
#include "test.h"
#include "liczba.h"
#include "stack.h"
#include "calc.h"
using namespace std;

//
//TEST LICZBY
//

void Test::testLiczba() {
//DECIMAL
    Dec *liczbaDec = new Dec();
    cout << "Tests of convertations numbers(in decimal) 17, 135, 879 to hex, bin and oct" << endl;
    cout << "CONVERT TO BIN: " << endl;
    cout << "Here expected \"10001\", \"10000111\", \"1101101111\": "<< liczbaDec->decBin(17)<<", " << liczbaDec->decBin(135) <<", "<< liczbaDec->decBin(879) <<endl;

    cout << "CONVERT TO OCT: " << endl;
    cout << "Here expected \"21\", \"207\", \"1557\": "<< liczbaDec->decOct(17)<<", " << liczbaDec->decOct(135) <<", "<< liczbaDec->decOct(879) <<endl;

    cout << "CONVERT TO HEX: " << endl;
    cout << "Here expected \"11\", \"87\", \"36F\": ";
    cout<< liczbaDec->decHex(17) <<", ";
    cout<< liczbaDec->decHex(135) <<", ";
    cout<< liczbaDec->decHex(879) <<endl;
    delete liczbaDec;

//BINARY
    cout << "---------------------------" <<endl;
    Bin *liczbaBin = new Bin();
    cout << "Tests of convertations numbers(in binary) 11011, 11011011, 111110010 to hex, dec and oct" << endl;
    cout << "CONVERT TO DEC: " << endl;
    cout << "Here expected \"27\", \"219\", \"498\": "
    << liczbaBin->binDec(11011)<<", " << liczbaBin->binDec(11011011) <<", "<< liczbaBin->binDec(111110010) <<endl;

    cout << "CONVERT TO OCT: " << endl;
    cout << "Here expected \"33\", \"333\", \"762\": "
    << liczbaBin->binOct(11011)<<", " << liczbaBin->binOct(11011011) <<", "<< liczbaBin->binOct(111110010) <<endl;

    cout << "CONVERT TO HEX: " << endl;
    cout << "Here expected \"1B\", \"DB\", \"1F2\": ";
    cout<< liczbaBin->binHex(11011)<<", ";
    cout << liczbaBin->binHex(11011011) <<", ";
    cout<< liczbaBin->binHex(111110010) <<endl;
    delete liczbaBin;

//OCTAL
    cout << "---------------------------" <<endl;
    Oct *liczbaOct = new Oct();
    cout << "Tests of convertations numbers(in octal) 30, 67, 102 to hex, dec and bin" << endl;
    cout << "CONVERT TO DEC: " << endl;
    cout << "Here expected \"24\", \"55\", \"66\": "
    << liczbaOct->octDec(30)<<", " << liczbaOct->octDec(67) <<", "<< liczbaOct->octDec(102) <<endl;

    cout << "CONVERT TO BIN: " << endl;
    cout << "Here expected \"11000\", \"110111\", \"1000010\": "
    << liczbaOct->octBin(30)<<", " << liczbaOct->octBin(67) <<", "<< liczbaOct->octBin(102) <<endl;

    cout << "CONVERT TO HEX: " << endl;
    cout << "Here expected \"18\", \"37\", \"42\": ";
    cout<< liczbaOct->octHex(30)<<", ";
    cout << liczbaOct->octHex(67) <<", ";
    cout<< liczbaOct->octHex(102) <<endl;
    delete liczbaOct;

//HEXADECIMAL
    cout << "---------------------------" <<endl;
    Hex *liczbaHex = new Hex();
    cout << "Tests of convertations numbers(in hexidecimal) 1D, 280, 3AF to oct, dec and bin" << endl;
    cout << "CONVERT TO DEC: " << endl;
    cout << "Here expected \"29\", \"640\", \"943\": "
    << liczbaHex->hexDec("1D")<<", " << liczbaHex->hexDec("280") <<", "<< liczbaHex->hexDec("3AF") <<endl;

    cout << "CONVERT TO BIN: " << endl;
    cout << "Here expected \"11101\", \"1010000000\", \"1110101111\": "
    << liczbaHex->hexBin("1D")<<", " << liczbaHex->hexBin("280") <<", "<< liczbaHex->hexBin("3AF") <<endl;

    cout << "CONVERT TO OCT: " << endl;
    cout << "Here expected \"35\", \"1200\", \"1657\": "
    << liczbaHex->hexOct("1D")<<", " << liczbaHex->hexOct("280") <<", "<< liczbaHex->hexOct("3AF") <<endl;
    delete liczbaHex;
}

//
//TEST STOSU
//

void Test::testStack() {
    Stack<char> stackSymbol(5);

    cout << "\n---------------------------\nEnter 5 chars: " << endl;
    int ct = 0;
    char ch;

    while (ct++ < 5)
    {
        cin >> ch;
        stackSymbol.push(ch); // помещаем элементы в стек
    }

    cout << endl;
    cout << "You have pushed 5 elements" << endl;
    stackSymbol.printStack(); // печать стека

    cout << "\n\nLet's delete element from stack\n";
    stackSymbol.pop();

    stackSymbol.printStack(); // печать стека

    Stack<char> newStack(stackSymbol);

    cout << "\n\nCopy constructor have worked\n";
    newStack.printStack();

    cout << "Second element in stack is: "<< newStack.Peek(2) << endl;

}

//
//TEST KALKULATORA
//

void Test::testCalc() {
    Calc calc;
    cout << "Calculator test(decimal): " << endl;
    cout << "Input\n" << endl;

    stack<double> calcStack;
    string input;
    if( calcStack.size() > 2 )                      //Error check gives a false error for last input ???
    {
        cout << "Error: too many operands" << endl;
        // return 1;
    }
    else if(calc.isOperator(input))
    {
        calc.performOperation(input, calcStack);
    }
    else if(input == "=")
    {
        if (calcStack.size() != 1)
        {
            cout << "Error: too many operands" << endl;
            // return 1;
        }
        else
        {
            cout << "Result: " << calcStack.top();
            calcStack.pop();
        }
    }


    while(input != "0")
    {
            //Terminate program when 0 is entered by user
        while(input != "=")
        {
            // get input
        cin >> input;
            // check for being numeric value
        double num;

            if(istringstream(input) >> num)
            {
                    //use push function
                    calcStack.push(num);
            }
            else if(calc.isOperator(input))
            {
                calc.performOperation(input, calcStack);
            }
            else if(input == "0\n")
            {
                // return -1;
            }
        }
    }
    // cout << "Do you want to test calculator in hex, oct or bin?\n" << endl;
    // cout << "1.Bin\t\t2.Oct\t\t3.Hex\t\t4.Exit" <<endl;
    // int flag;
    // cin >> flag;
    // switch (flag)
    // {
    // case 1:
    //     /* code */
    //     break;
    // case 2:
    //     /* code */
    //     break;
    // case 3:
    //     /* code */
    //     break;
    // case 4:

    //     break;

    // default:
    //     break;
    // }
}
