#include "iostream"
#include "Stack.h"
using namespace std;
#ifndef AADT_LAB1_SORTSTATION_H
#define AADT_LAB1_SORTSTATION_H


class SortStation {
public:
    std::string getStr();

    int priority(char c);

    double operation(double a, double b, char c);

    bool calculate(std::string &output);

    std::string toRPN(std::string &inputStr, bool &errorFlag);
};



#endif //AADT_LAB1_SORTSTATION_H
