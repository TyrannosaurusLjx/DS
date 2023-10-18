#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <cstdlib>
#include <cctype>
#include "stringPreproce.h"


// op优先级判断函数
int op_Priority(char op){
    if(op == '+' || op == '-'){
        return 1;
    }else if(op == '*' || op == '/'){
        return 2;
    }else if(op == '(' || op == ')'){
        return 3;
    }else{
        return 0;
    }
}


int main(int argc, char* argv[]){
    std::string infix;
    infix = argv[1];
    infix = strPreproce(infix);
    std::cout<<infix<<std::endl;
    

    
    return 0;
}