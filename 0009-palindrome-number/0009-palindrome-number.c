bool isPalindrome(int x) {
    if (x < 0) return false;
    int o = x;
    long long rev = 0; 

    while (x != 0) {
        int q = x % 10;     
        rev = rev * 10 + q; 
        x = x / 10;
    }

    return rev == o;
}