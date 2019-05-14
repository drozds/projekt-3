#ifndef LICZBA_H
#define LICZBA_H
#include <string>
#include <cmath>
using namespace std;

class Liczba {
    public:
//Dziesietny
    int decBin(int value) {
        int binaryNum, count = 1;
        while (value != 0) {
            binaryNum += (value % 2) * count;
            value/= 2;
            count *= 10;
        }
        return binaryNum;
    }
    int decOct(int value) {
        int binaryNum, count = 1;
        while (value != 0) {
            binaryNum += (value % 8) * count;
            value/= 8;
            count *= 10;
        }
        return binaryNum;
    }
    string decHex(int value) {
        int temp, i = 1, j, r;
        char hex[50];
        temp = value;
        while (temp != 0)
        {
            r = temp % 16;
            if (r < 10)
                hex[i++] = r + 48;
            else
                hex[i++] = r + 55;
            temp = temp / 16;
        }
        for (j = i; j > 0; j--)
            cout << hex[j];
        return "";
    }
//Dwojkowy
    int binDec(int value) {
        int decimalNum = 0, count = 0;
        while(value != 0) {
            decimalNum += (value % 10) * pow(2,count);
            ++count;
            value/=10;
        }
        return decimalNum;
    }
    int binOct(int value) {
        int octalNum = 0, decimalNum = 0, count = 0;
   
        while(value != 0) {
            decimalNum += ( value % 10) * pow(2,count);
            ++count; 
            value /= 10;
        }
        count = 1;
        while (decimalNum != 0) {
            octalNum += (decimalNum % 8) * count;
            decimalNum /= 8;
            count *= 10;
        }
        return octalNum;
    }
    string binHex(int value) {
        int number = binDec(value);
        int temp, i = 1, j, r;
        char hex[50];
        temp = number;
        while (temp != 0)
        {
            r = temp % 16;
            if (r < 10)
                hex[i++] = r + 48;
            else
                hex[i++] = r + 55;
            temp = temp / 16;
        }
        for (j = i; j > 0; j--)
            cout << hex[j];
        return "";
    }
//Osemkowy
    int octBin(int value) {
        int decimalNum = 0, binaryNum = 0, count = 0;
        while(value != 0) {
            decimalNum += (value % 10) * pow(8,count);
            ++count;
            value/=10;
        }
        count = 1;
        while (decimalNum != 0) {
            binaryNum += (decimalNum % 2) * count;
            decimalNum /= 2;
            count *= 10;
        }
        return binaryNum;
    }
    int octDec(int value) {
        int decimalNum = 0, count = 0;
        while(value != 0) {
            decimalNum += (value % 10) * pow(8,count);
            ++count;
            value/=10;
        }
        return decimalNum;
    }
    string octHex(int value) {
        int number = octDec(value);
        int temp, i = 1, j, r;
        char hex[50];
        temp = number;
        while (temp != 0)
        {
            r = temp % 16;
            if (r < 10)
                hex[i++] = r + 48;
            else
                hex[i++] = r + 55;
            temp = temp / 16;
        }
        for (j = i; j > 0; j--)
            cout << hex[j];
        return "";
    }
//Szesnastkowy
    int hexBin(string value) {
        int result = 0;
        for (long long unsigned int i=0; i < value.length(); i++) {
            if (value[i]>=48 && value[i]<=57)
            {
                result += (value[i]-48)*pow(16,value.length()-i-1);
            } else if (value[i]>=65 && value[i]<=70) {
                result += (value[i]-55)*pow(16,value.length( )-i-1);
            } else if (value[i]>=97 && value[i]<=102) {
                result += (value[i]-87)*pow(16,value.length()-i-1);
            }
        }
        return decBin(result);
    }
    int hexOct(string value) {
        int result = 0;
        for (long long unsigned int i=0; i < value.length(); i++) {
            if (value[i]>=48 && value[i]<=57)
            {
                result += (value[i]-48)*pow(16,value.length()-i-1);
            } else if (value[i]>=65 && value[i]<=70) {
                result += (value[i]-55)*pow(16,value.length( )-i-1);
            } else if (value[i]>=97 && value[i]<=102) {
                result += (value[i]-87)*pow(16,value.length()-i-1);
            }
        }
        return decOct(result);
    }
    int hexDec(string value) {
        int result = 0;
        for (long long unsigned int i=0; i < value.length(); i++) {
            if (value[i]>=48 && value[i]<=57)
            {
                result += (value[i]-48)*pow(16,value.length()-i-1);
            } else if (value[i]>=65 && value[i]<=70) {
                result += (value[i]-55)*pow(16,value.length()-i-1);
            } else if (value[i]>=97 && value[i]<=102) {
                result += (value[i]-87)*pow(16,value.length()-i-1);
            }
        }
        return result;
    }

};

class Dec : public Liczba {
    public:
    Dec();
    int dec;
}; 

class Oct : public Liczba {
    public:
    Oct();
    int oct;
}; 

class Bin : public Liczba {
    public:
    Bin();
    int bin;
}; 

class Hex : public Liczba {
    public:
    Hex();
    string hex;
}; 

#endif