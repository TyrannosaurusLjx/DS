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
bool bracketCheck(std::string str){
    bool result = true;
    char ch=' ',leftch = ' ',rightch=' ';
    // 括号栈
    std::stack<char> bracketStack;
    for(int i=0; i < str.length(); i++){
        ch = str[i];

        // 两端分别判断
        if(i == 0){
            rightch = str[i+1];
            if(ch == ')' || rightch == '*' || rightch == '/' || ispoint(rightch) || rightch == ')'){
                result = false;
                break;
            }
        }else if(i == str.length()-1){
            leftch = str[i-1];
            if(ch == '(' || (ch == ')' && !(isdigit(leftch) || leftch == ')') )){
                result = false;
                break;
            }
        }
        
        // 中间
        leftch = str[i-1];
        rightch = str[i+1];
        // 括号左右不合法处理
        if(ch == '('){
            if(isdigit(leftch) || ispoint(leftch) || leftch == ')' || rightch == '*' || rightch == '/' || ispoint(rightch) || rightch == ')'){
                result = false;
                break;
            }else{
                bracketStack.push(ch);
            }
        }else if(ch == ')'){
            if(!(isdigit(leftch) || leftch == ')') || rightch == '(' || isdigit(rightch) || ispoint(rightch)){
                result = false;
                break;
            }else{
                if( !bracketStack.empty() && bracketStack.top() == '('){
                    bracketStack.pop();
                }else{
                    result = false;
                    break;
                }
            }
        }
    }
    return result;
}

// 操作符处理
bool opCheck(std::string& str){
    bool result = true;
    char ch;
    for(int i = 0; i < str.length(); i++){
        ch = str[i];
        if(isFourOp(ch)){
            if(isFourOp(str[i+1])){
                result = false;
                break;
            }
        }
    }
    return result;
}

// 小数点
// bool isDecimalValid(const std::string& str) {  
//     int dotCount = 0;  
//     int dotIndex = -1;  
  
//     for (int i = 0; i < str.length(); i++) {  
//         if (str[i] == '.') {  
//             dotCount++;  
//             dotIndex = i;  
//         }  
//     }  
  
//     // 判断小数点的数量和位置是否符合预期规则  
//     if (dotCount == 1 && dotIndex > 0 && dotIndex < str.length() - 1) {  
//         return false;  
//     } else {  
//         return true;  
//     }  
// }  



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
    // // 小数点
    // if(isDecimalValid(preInfix) != true){
    //     err_exp();
    // }
    infix = preInfix;
    return infix;
}

// 字符串转queue
std::queue<std::string> strToQueue(std::string infix){
    std::queue<std::string> result;
    std::string item;
    bool atNum = true;
    char ch;
    for(int i = 0; i < infix.length(); i++){
        ch = infix[i];
        
        if(isop(ch)){
            atNum = false;
        }else{
            atNum = true;
        }
        if(atNum){
            item += ch;
        }else{
            if(item != ""){
                result.push(item);
            }
            item = "";
            result.push(std::string (1,ch));
        }
    }
    // 最后一个字母
    if(atNum){
        result.push(std::string (1,ch));
    }

    return result;
}

