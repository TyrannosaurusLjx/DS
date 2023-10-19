#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <cstdlib>
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


int main(int argc, char* argv[]){
    std::queue<std::string> Postfix;//后缀表达式队列
    std::queue<std::string> infixQueue; //中缀表达式队列
    std::stack<std::string> opStack;
    infixQueue = strToQueue(strPreproce(argv[1]));
    while (!infixQueue.empty())
    {
        /* code */
        std::cout<<infixQueue.front()<<std::endl;
        infixQueue.pop();
    }

    bool result = isnum("9.6");  
    std::cout << std::boolalpha << result << std::endl; 
    std::cout<<op_Priority("+")<<op_Priority("*")<<std::endl;


    std::string item;
    while (!infixQueue.empty()){
        item = infixQueue.front();

        if(isnum(item)){
            Postfix.push(item);
            infixQueue.pop();
            continue;
        }else if(item == "("){
            opStack.push(item);
            infixQueue.pop();
            continue;
        }else if(item == ")"){
            while (opStack.top() != "("){
                Postfix.push(opStack.top());
                opStack.pop();
            }
            opStack.pop();
        }else{
            while(!opStack.empty() && op_Priority(opStack.top()) >= op_Priority(item) && opStack.top() != "("){
                Postfix.push(opStack.top());
                opStack.pop();
            }
            opStack.push(item);
        }
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

// int main(int argc, char* argv[]){
//     // 后缀表达式队列
//     std::queue<std::string> Postfix;
//     // 中缀表达式队列
//     std::queue<std::string> infixQueue;
//     // 操作符栈
//     std::stack<std::string> opStack;
    
//     // 字符序列 meiyong
//     std::string infix;
//     infix = strPreproce(argv[1]);

//     std::cout<<infix<<std::endl;
//     infixQueue = strToQueue(infix);


//     std::string ch = "";
//     for(int i = 0; i < infixQueue.size(); i++){
//         ch = infix[i];
//         if(i == 0 && ch == "-"){
//             Postfix.push("0");
//         }
//         // num and .直接push
//         if(isnum(ch)){
//             Postfix.push(ch);
//             Postfix.push(" ");
//             continue;
//         }else if(ch == "("){
//             opStack.push(ch);
//         }else if(ch == ")"){
//             while(opStack.top() != "("){
//                 Postfix.push(opStack.top());
//                 opStack.pop();
//             }
//             // pop (
//             opStack.pop();
//         }else{
//             while(!opStack.empty() && op_Priority(opStack.top()) >= op_Priority(ch) && opStack.top() != "("){
//                 Postfix.push(opStack.top());
//                 Postfix.push(" ");
//                 opStack.pop();
//             }
//             opStack.push(ch);
//         }
//     }
//     while(!opStack.empty()){
//         Postfix.push(opStack.top());
//         opStack.pop();
//     }
//     while(!Postfix.empty()){
//         std::cout<<Postfix.front();
//         Postfix.pop();
//     }
//     std::cout<<" "<<std::endl;

//     return 0;
// }

