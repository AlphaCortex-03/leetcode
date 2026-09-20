#include <limits.h>

int reverse(int x) {
    int rev = 0;
    while (x != 0) {
        int q = x % 10;
        
        // Check for potential overflow/underflow before multiplying
        if (rev > INT_MAX / 10 || rev < INT_MIN / 10) {
            return 0;
        }
        
        rev = rev * 10 + q;
        x /= 10;
    }
    return rev;
}
