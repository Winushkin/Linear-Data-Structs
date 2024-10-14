#include "SortStation.h"
#include "iostream"

using namespace std;


string SortStation::getStr() {
    string input;
    getline(cin, input);
    return input;
}


int SortStation::priority(char c) {
    switch (c){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        case '(':
        case ')':
            return 0;
        case ' ':
            return 10;
        default:
            if (isdigit(c)) return -1;
            else if (c >= 'a' && c < 'z' || c >= 'A' && c <= 'Z') return -1;
            else return -2;
    }
}


double SortStation::operation(double a, double b, char c) {
    switch (c){
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '^':
            return pow(a, b);
        default:
            return 0;
    }
}


string SortStation::toRPN(string &inputStr, bool &errorFlag) {
    auto *stack = new Stack<string>();
    string output, cur;
    int strlen = inputStr.length();

    for( int i = 0; i < strlen; i++){
        if ( cur == "sin" || cur == "cos" ){
            stack->push(cur, 2);
            cur.clear();
        }
        switch (priority(inputStr[i])) {
            case -1:
                cur.push_back(inputStr[i]);
                break;

            case 0:
                if ( !cur.empty() ){
                    output += cur + " ";
                    cur.clear();
                }
                if ( inputStr[i] == '(' ){
                    stack->push("(", 0);
                }else{
                    while (true){
                        if ( stack->head == nullptr){
                            errorFlag = true;
                            return " ";
                        }
                        if ( stack->head->data == "(" ) break;
                        output += stack->head->data;
                        output.push_back(' ');
                        stack->pop();
                    }
                    stack->pop();

                }
                break;

            case 1:
            case 2:
            case 3:
                if ( !cur.empty() ){
                    output += cur + " ";
                    cur.clear();
                }
                if ( !stack->head || stack->head->priority < priority(inputStr[i]) ){
                    stack->push(inputStr.substr(i ,1), priority(inputStr[i]));
                }else{
                    while ( stack->head && stack->head->priority >= priority(inputStr[i]) ){
                        output += stack->head->data;
                        output.push_back(' ');
                        stack->pop();
                    }
                    stack->push(inputStr.substr(i,1), priority(inputStr[i]));
                }
                break;

            case 10:
                if ( !cur.empty() ){
                    output = cur + " ";
                    cur.clear();
                }
                break;
        }
    }
    if(!cur.empty()) {
        output += cur + " ";
        cur.clear();
    }
    while(stack->head != nullptr){
        output += stack->head->data;
        output.push_back(' ');
        stack->pop();
    }
    delete stack;
    return output;
}


bool SortStation::calculate(string &output) {
    auto* pStack = new Stack<string>();
    string cur;
    double result = 0;
    double variable = 0;
    int strLen = output.length();

    for(int i = 0; i < strLen; i++){
        if(output[i] != ' '){
            switch(priority(output[i])){
                case -1:
                    cur.push_back(output[i]);
                    break;

                case 0:
                    return false;

                case 1:
                case 2:
                case 3:
                    if (pStack->head == pStack->tail){
                        cout << "\nОшибка ввода строки! Недостаточно операндов.\n";
                        return false;
                    }
                    if(!isdigit(pStack->head->data[0])){
                        variable = 1;
                    }else variable = stod(pStack->head->data);

                    result = variable;
                    pStack->pop();

                    if (output[i] == '/' && result == 0){
                        cout << "\nДеление на ноль невозможно!\n";
                        return false;
                    }
                    if(!isdigit(pStack->head->data[0])){
                        variable = 1;
                    }else variable = stod(pStack->head->data);

                    result = operation(variable, result, output[i]);
                    pStack->pop();
                    cur = to_string(result);
                    pStack->push(cur, -1);
                    cur = "";
                    break;

                default:
                    cout << "\nОшибка ввода строки.";
                    return false;
            }
        }else{
            if (!cur.empty()) {
                if(cur == "sin"){
                    if (pStack->head == nullptr){
                        cout << "\nОшибка ввода строки! Недостаточно операндов.\n";
                        return false;
                    }

                    if(!isdigit(pStack->head->data[0])){
                        variable = 1;
                    } else variable = stod(pStack->head->data);

                    result = sin(variable);
                    pStack->pop();
                    cur = to_string(result);
                    pStack->push(cur, -1);

                }else if(cur == "cos"){
                    if (pStack->head == nullptr){
                        cout << "\nОшибка ввода строки! Недостаточно операндов.\n";
                        return false;
                    }
                    if(!isdigit(pStack->head->data[0])){
                        variable = 0;
                    }else variable = stod(pStack->head->data);

                    result = cos(variable);
                    pStack->pop();
                    cur = to_string(result);
                    pStack->push(cur, -1);

                }else{
                    pStack->push(cur, -1);
                }
                cur = "";
            }
        }
    }
    if (pStack->head != pStack->tail){
        cout << "\nОшибка ввода! Недостаточно операций.\n";
        return false;
    }
    return true;
}
