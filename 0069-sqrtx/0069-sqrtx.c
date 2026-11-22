int mySqrt(int x) {
    if (x < 2) {
        return x;
    }

    long long r = x;
    while (r * r > (long long)x) {
        r = (r + (long long)x / r) / 2;
    }

    return (int)r;
}