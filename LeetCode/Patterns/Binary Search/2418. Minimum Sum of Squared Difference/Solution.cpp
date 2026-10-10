
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        vector<int> cnt(100001, 0);
        long long sum = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            cnt[d]++;
            sum += d;
        }

        if (sum <= k) return 0;

        for (int d = 100000; d > 0 && k > 0; d--) {
            if (cnt[d] == 0) continue;

            long long take = min(k, (long long)cnt[d]);
            long long full = min(k / cnt[d], (long long)d);

            if (full > 0) {
                long long moved = min(k, full * cnt[d]);
                cnt[d] -= 0; 
                cnt[d - 1] += (int)(moved / full);
                k -= moved;
            }

            if (k > 0 && cnt[d] > 0) {
                long long moves = min(k, (long long)cnt[d]);
                cnt[d] -= moves;
                cnt[d - 1] += moves;
                k -= moves;
            }
        }

        long long ans = 0;
        for (int d = 1; d <= 100000; d++) {
            ans += 1LL * d * d * cnt[d];
        }

        return ans;
    }
};
