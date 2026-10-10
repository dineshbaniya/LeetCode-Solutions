
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        vector<int> diff(nums1.size());
        long long sum = 0;
        int mx = 0;

        for (int i = 0; i < nums1.size(); i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            sum += diff[i];
            mx = max(mx, diff[i]);
        }

        if (sum <= k) return 0;

        vector<int> cnt(mx + 1, 0);
        for (int d : diff) cnt[d]++;

        for (int d = mx; d > 0 && k > 0; d--) {
            if (cnt[d] == 0) continue;

            long long moves = min(k, (long long)cnt[d]);
            cnt[d] -= moves;
            cnt[d - 1] += moves;
            k -= moves;
        }

        long long ans = 0;
        for (int d = 1; d <= mx; d++) {
            ans += 1LL * d * d * cnt[d];
        }

        return ans;
    }
};
