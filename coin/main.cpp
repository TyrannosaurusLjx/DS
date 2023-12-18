#include <iostream>
#include"coin.h"
#include<numeric>

int main(){
    std::vector<int>result(4, 0);
   //examples for testing
   std::vector<int>testN = {1,4,9,24,41,99,126};
    std::cout<<"1 5 10 25"<<std::endl;
    for(const auto &test: testN){
        std::vector<int>X0(4,0);
        result = coin(test, X0);

        for (const auto &element : result) {  
            std::cout << element << " ";  
        }  

    std::cout<< "total:"<<std::accumulate(result.begin(), result.end(), 0)<<std::endl;
    }
    return 0;
}
