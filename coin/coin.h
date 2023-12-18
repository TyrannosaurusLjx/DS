#include <vector>  

// dynamic programming
std::vector<int> coin(int n, std::vector<int> &result) {  
    if (n >= 25) {  
        result[3] += n / 25;  
        return coin(n % 25, result);  
    } else if (n >= 10) {  
        result[2] += n / 10;  
        return coin(n % 10, result);  
    } else if (n >= 5) {  
        result[1] += n / 5;  
        return coin(n % 5, result);  
    } else {  
        result[0] += n;  
        return result;  
    }  
}  
