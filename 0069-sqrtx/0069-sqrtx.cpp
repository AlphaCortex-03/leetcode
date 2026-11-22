class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) {
            return x;
        }

        int low = 1;
        int high = x / 2;
        int ans = 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long square = 1LL * mid * mid;

            if (square == x) {
                return mid;
            }
            if (square < x) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};