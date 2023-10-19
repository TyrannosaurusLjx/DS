#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <cctype>
#include "stringPreproce.h"


// op优先级判断函数
int op_Priority(std::string op){
    op = op[op.length()-1];
    if(op == "+" || op == "-"){
        return 1;
    }else if(op == "*" || op == "/"){
        return 2;
    }else if(op == "(" || op == ")"){
        return 3;
    }else{
        return 0;
    }
}

// 判断数和小数
bool isnum(std::string str){
    if(isdigit(str[str.size()-1])){
        return true;
    }else{
        return false;
    }
}

// string中dot个数
int countDots(const std::string& str) {  
    int count = 0;  
    for (char c : str) {  
        if (c == '.') {  
            count++;  
        }  
    }  
    return count;  
}  
  

int main(int argc, char* argv[]){
    std::queue<std::string> Postfix;//后缀表达式队列
    std::queue<std::string> infixQueue; //中缀表达式队列
    std::stack<std::string> opStack;
    infixQueue = strToQueue(strPreproce(argv[1]));


    std::string item;
    while (!infixQueue.empty()){
        item = infixQueue.front();
        if(countDots(item) > 1){
            err_exp();
        }
        if(isnum(item)){

            Postfix.push(item);
        }else if(item == "("){
            opStack.push(item);
        }else if(item == ")"){
            while (opStack.top() != "("){
                Postfix.push(opStack.top());
                opStack.pop();
            }
            // pop (
            opStack.pop();
        }else{
            while(!opStack.empty() && (op_Priority(opStack.top()) >= op_Priority(item)) && opStack.top() != "("){
                Postfix.push(opStack.top());
                opStack.pop();
            }
            opStack.push(item);
        }
        // next
        infixQueue.pop();
        continue;
    }
    while (!opStack.empty()){
        Postfix.push(opStack.top());
        opStack.pop(); 
    }
    
    while(!Postfix.empty()){
        std::cout<<Postfix.front()<<std::endl;
        Postfix.pop();
    }
    std::cout<<" "<<std::endl;
    
    return 0;
    
}
