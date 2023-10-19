#include <iostream>  
#include <stack>  
#include <queue>  
#include <string>  
#include <cstdlib>  
#include <cctype>  
#include "stringPreproce.h"  
  
// op优先级判断函数  
int op_Priority(char op) {  
    if (op == '+' || op == '-') {  
        return 1;  
    } else if (op == '*' || op == '/') {  
        return 2;  
    } else if (op == '(' || op == ')') {  
        return 3;  
    } else {  
        return 0;  
    }  
}  
  
// 判断字符是否为小数点  
bool isPoint(char ch) {  
    return ch == '.';  
}  
  
int main(int argc, char* argv[]) {  
    // 后缀表达式队列  
    std::queue<char> Postfix;  
    // 操作符栈  
    std::stack<char> opStack;  
    // 字符序列  
    std::string infix;  
    infix = strPreproce(argv[1]);  
  
    std::cout << infix << std::endl;  
  
    char ch = ' ';  
    bool isDecimal = false; // 标记是否正在处理小数部分  
    std::string decimalPart; // 保存小数部分的字符序列  
  
    for (int i = 0; i < infix.length(); i++) {  
        ch = infix[i];  
        if (i == 0 && ch == '-') {  
            Postfix.push('0');  
        }  
        // num and .直接push  
        if (isdigit(ch) || isPoint(ch)) {  
            if (isPoint(ch)) {  
                isDecimal = true;  
            }  
            if (isDecimal) {  
                decimalPart += ch;  
            } else {  
                Postfix.push(ch);  
                Postfix.push(' ');  
            }  
            continue;  
        } else if (ch == '(') {  
            opStack.push(ch);  
        } else if (ch == ')') {  
            while (opStack.top() != '(') {  
                Postfix.push(opStack.top());  
                opStack.pop();  
            }  
            // pop (  
            opStack.pop();  
        } else if (isFourOp(ch)) {  
            while (!opStack.empty() && op_Priority(opStack.top()) >= op_Priority(ch) && opStack.top() != '(') {  
                Postfix.push(opStack.top());  
                Postfix.push(' ');  
                opStack.pop();  
            }  
            opStack.push(ch);  
        }  
    }  
  
    // 处理小数部分  
    if (isDecimal) {  
        Postfix.push('.');  
        for (char decimalChar : decimalPart) {  
            Postfix.push(decimalChar);  
        }  
        Postfix.push(' ');  
    }  
  
    while (!opStack.empty()) {  
        Postfix.push(opStack.top());  
        opStack.pop();  
    }  
  
    while (!Postfix.empty()) {  
        std::cout << Postfix.front();  
        Postfix.pop();  
    }  
  
    std::cout << " " << std::endl;  
  
    return 0;  
}  