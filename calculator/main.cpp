#include "bits/stdc++.h"

using namespace std;

const char compare[7][7]{
        {'>', '>', '<', '<', '<', '>', '>'},
        {'>', '>', '<', '<', '<', '>', '>'},
        {'>', '>', '>', '>', '<', '>', '>'},
        {'>', '>', '>', '>', '<', '>', '>'},
        {'<', '<', '<', '<', '<', '=', '='},
        {'>', '>', '>', '>', '=', '>', '>'},
        {'<', '<', '<', '<', '<', '=', '='},
};

int getNum(char op) {
    switch (op) {
        //因为直接 return 了所以不用break
        case '+':
            return 0;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 3;
        case '(':
            return 4;
        case ')':
            return 5;
        case '#':
            return 6;
        default :
            exit(3);
    }
}

char precede(char opIn, char opOut) {
    return compare[getNum(opIn)][getNum(opOut)];
}

int calculate(int a, char op, int b) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            exit(1);
    }
}

int main() {
    stack<int> OPND;
    stack<char> OPTR;
    OPTR.push('#');
    char input;
    int inputNum = 0;
    bool flag = true;
    cout << "请输入一串算式（仅包含 +, -, *, /, (, ) ），以 '#' 结尾" << endl;
    input = cin.get();
    while (input != '#' || OPTR.top() != '#') {
        if (input >= '0' && input <= '9') {
            inputNum = inputNum * 10 + input - '0';
            input = cin.get();
            flag = false;
        } else if (input == '+' || input == '-' || input == '*' || input == '/' || input == '(' || input == ')' || input == '#') {
            if(!flag) {
                OPND.push(inputNum);
                inputNum = 0;
                flag = true;
            }
            if (precede(OPTR.top(), input) == '<') {
                OPTR.push(input);
                input = cin.get();
            } else if (precede(OPTR.top(), input) == '=') {
                OPTR.pop();
                input = cin.get();
            } else {
                int b = OPND.top();
                OPND.pop();
                int a = OPND.top();
                OPND.pop();
                char op = OPTR.top();
                OPTR.pop();
                OPND.push(calculate(a, op, b));//出栈顺序相反
            }
        } else if (input == ' ') {
            input = cin.get();
        } else {
            exit(2);
        }
    }
    cout << "= " << OPND.top() << endl;
    return 0;
}