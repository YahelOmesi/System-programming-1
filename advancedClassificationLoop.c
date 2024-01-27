#include "NumClass.h"
#include <stdio.h>

//Helper function 1
int power(int base, int exponent){
    int result = 1;
    for(int i = 0; i < exponent; i++){
        result *= base;
    }
    return result;
}

//Helper function 2
int countDigit(int x){
    int counter = 0;
    while(x != 0){
        x /= 10;
        ++counter;
    }
    return counter;
}

int isArmstrong(int x){
    int xCopy = x;
    int e = countDigit(x);
    int sum = 0;

    while(x > 0){
    int currentBase = x % 10;
    sum = sum + power(currentBase,e);
    x = x/10;
    }

    if(xCopy == sum){
        return 1;
    }return 0;
}


int isPalindrome(int x){
    int original = x;
    int reverse  = 0;

    while(x > 0){
        int digit = x % 10;
        reverse = (reverse*10) + digit;
        x = x / 10;
    }
    return (original == reverse);
}