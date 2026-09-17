class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        vector<int> best(n, INF);

        int left = 0;
        int sum = 0;
        int ans = INF;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left++];
            }

            // Carry forward the previous best subarray
            if (right > 0)
                best[right] = best[right - 1];

            // Found a subarray with sum = target
            if (sum == target) {
                int len = right - left + 1;

                // Combine with a non-overlapping previous subarray
                if (left > 0 && best[left - 1] != INF) {
                    ans = min(ans, best[left - 1] + len);
                }

                // Best single subarray ending at or before right
                best[right] = min(best[right], len);
            }
        }

        return ans == INF ? -1 : ans;
    }
};