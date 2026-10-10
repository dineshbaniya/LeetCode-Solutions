
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> diff(nums1.size());
        long long k = (long long)k1 + k2;
        long long total = 0;

        for (int i = 0; i < nums1.size(); i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
        }

        if (total <= k) return 0;

        sort(diff.rbegin(), diff.rend());

        int n = diff.size();

        for (int i = 0; i < n; i++) {
            long long next = (i == n - 1) ? 0 : diff[i + 1];
            long long need = 1LL * (i + 1) * (diff[i] - next);

            if (k >= need) {
                k -= need;
                for (int j = 0; j <= i; j++) {
                    diff[j] = next;
                }
            } else {
                long long level = diff[i] - k / (i + 1);
                long long rem = k % (i + 1);

                long long ans = 0;

                for (int j = 0; j <= i; j++) {
                    long long d = level - (j < rem ? 1 : 0);
                    ans += d * d;
                }

                for (int j = i + 1; j < n; j++) {
                    ans += 1LL * diff[j] * diff[j];
                }

                return ans;
            }
        }

        return 0;
    }
};
