#include "NumClass.h"
#include <stdio.h>

int isPrime(int x)
{

    if(x < 1){
        return 0;
    }

    if(x == 1){
        return 1;
    }

    for(int i = 2; i*i <= x ; i++){
        if(x % i == 0){
            return 0;
        }
    } 
    return 1; 
}

int factorial(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    else{
        int result = 1;
        for(int i = 2; i <= n; i++){
        result *= i;
        }
        return result;
    }
}

// int isStrong(int x){
//     if(factorial(x) == x){
//         return 1;
//     } return 0;
// }

int isStrong(int x){
    int original = x;
    int sum = 0;
    
    while(x > 0){
        int digit = x % 10;
        sum += factorial(digit);
        x /= 10;
    }

    return (sum == original);
}