#include <iostream>
#include <stack>
#include <string>
#include <cctype>

// 错误提示函数
void err_exp(){
    std::cout<<"Illegal Expressions!"<<std::endl;
    exit(-1);
    }

// 数据预处理函数
bool isop(char op){
    if(op == '+' || op == '-' || op == '*' || op == '/' || op == '(' || op == ')'){
        return true;
    }else{
        return false;
    }
};

bool isFourOp(char ch){
    if(isop(ch) && ch != '(' && ch != ')'){
        return true;
    }else{
        return false;
    }
}

bool ispoint(char op){
    if(op == '.'){
        return true;
    }else{
        return false;
    }
}

// 括号处理
bool bracketCheck(std::string& str){
    char ch=' ',leftch = ' ',rightch=' ';
    std::stack<char> bracketStack;
    for(int i=0; i < str.length(); i++){
        ch = str[i];

        // 两端分别判断
        if(i == 0){
            rightch = str[i+1];
            if(ch == ')' || rightch == '*' || rightch == '/' || ispoint(rightch) || rightch == ')'){
                err_exp();
            }
        }else if(i == str.length()-1){
            leftch = str[i-1];
            if(ch == '(' || !(isdigit(leftch) || leftch == ')')){
                err_exp();
            }
        }
        
        // 中间
        leftch = str[i-1];
        rightch = str[i+1];
        // 括号左右不合法处理
        if(ch == '('){
            if(isdigit(leftch) || ispoint(leftch) || leftch == ')' || rightch == '*' || rightch == '/' || ispoint(rightch) || rightch == ')'){
                err_exp();
            }else{
                bracketStack.push(ch);
            }
        }else if(ch == ')'){
            if(!(isdigit(leftch) || leftch == ')') || rightch == '(' || isdigit(rightch) || ispoint(rightch)){
                err_exp();
            }else{
                if( !bracketStack.empty() && bracketStack.top() == '('){
                    bracketStack.pop();
                }else{
                    err_exp();
                }
            }
        }
    }
    return true;
}

// 操作符处理
bool opCheck(std::string& str){
    char ch;
    for(int i = 0; i < str.length()-2; i++){
        ch = str[i];
        if(isFourOp(ch)){
            if(isFourOp(str[i+1])){
                err_exp();
            }
        }
    }
    return true;
}

// 总判断函数
std::string strPreproce(std::string infix){
    std::string preInfix;
    char ch;
    // 处理除了op,'.'和num以外的字符
    for(int i=0; i < infix.length(); i++){
        ch = infix[i];
        if(isdigit(ch) || ispoint(ch) || isop(ch)){
            preInfix += ch;
        }else if(isalpha(ch)){
            continue;
        }
    }
    // 检查括号合法性
    if(bracketCheck(preInfix) != true){
        err_exp();
    }
    // 检查运算合法性
    if(opCheck(preInfix) != true){
        err_exp();
    }

    
    infix = preInfix;
    return infix;
}
