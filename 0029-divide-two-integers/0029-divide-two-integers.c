#include <stdlib.h>
#include <limits.h>

int divide(int dividend, int divisor) {

    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }


    int negative = (dividend < 0) ^ (divisor < 0);


    long long dvd = llabs((long long)dividend);
    long long dvs = llabs((long long)divisor);

    long long quotient = 0;

    while (dvd >= dvs) {
        long long temp = dvs;
        long long multiple = 1;

    
        while (dvd >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }

        dvd -= temp;
        quotient += multiple;
    }

   
    long long result = negative ? -quotient : quotient;
    
    if (result > INT_MAX) return INT_MAX;
    if (result < INT_MIN) return INT_MIN;

    return (int)result;
}