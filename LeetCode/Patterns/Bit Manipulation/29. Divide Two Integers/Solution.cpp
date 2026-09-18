class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0)
            return 0;

        int a = abs(dividend);
        int b = abs(divisor);

        int ans = 0;

        while (a >= b) {
            a -= b;
            ans++;
        }

        if ((dividend < 0) != (divisor < 0))
            ans = -ans;

        return ans;
    }
};