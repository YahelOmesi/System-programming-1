#include "NumClass.h"
#include <stdbool.h>
#include <stdio.h>

//Helper function 1
int power(int base, int exponent){
    if(exponent == 0){
        return 1;
    }
    return base*power(base, exponent-1);
}

//Helper function 2
int countDigit(int x){
    if(x == 0){
        return 0;
    }return 1+countDigit(x/10);
}

int isArmstrongRecursive(int num, int original, int n) {
    if (num == 0) {
        return (original == 0) ? 1 : 0;
    } else {
        int digit = num % 10;
        return (power(digit, n) + isArmstrongRecursive(num / 10, original, n));
    }
}

int isArmstrongHelper(int x, int n){
    if(x == 0){
        return 0;
    }
    return (power((x%10),n))+ isArmstrongHelper(x/10,n);
}

int isArmstrong(int x){
int n = countDigit(x);
int countSum = isArmstrongHelper(x,n);
return (x == countSum) ? 1 : 0;
}

//Helper function 3
int isPalindromeRecursive(int x,int original, int digit){
    if(digit <= 1){
        return 1;
    }

    int firstDigit = x / (int)power(10,digit-1);
    int lastDigit = x % 10;

    if(firstDigit != lastDigit){
        return 0;
    }

    int subNumber = (x % (int)power(10,digit-1)) / 10;

    return isPalindromeRecursive(subNumber,original,digit-2); //Recursive call
}

int isPalindrome(int x){
    if(x < 0){
        return 0;
    }
    int digit = countDigit(x);
    return isPalindromeRecursive(x,x,digit);
}
