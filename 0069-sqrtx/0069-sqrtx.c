int mySqrt(int x) {
    if (x < 2) {
        return x;
    }

    int l = 1;
    int h = x / 2;
    int ans = 0;

    while (l <= h) {
        int mid = l+ (h - l) / 2;
        long long sq = (long long)mid * mid;

        if (sq == x) {
            return mid;
        } else if (sq < x) {
            ans = mid;
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }

    return ans;
}