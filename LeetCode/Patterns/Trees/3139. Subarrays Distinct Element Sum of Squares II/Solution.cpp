class Solution {
public:
    static const long long MOD = 1000000007LL;

    struct Node {
        long long sum = 0;
        long long sq = 0;
        long long lazy = 0;
    };

    vector<Node> tree;

    void apply(int p, int l, int r, long long x) {
        long long len = r - l + 1;

        tree[p].sq = (
            tree[p].sq
            + 2LL * x % MOD * tree[p].sum % MOD
            + x * x % MOD * (len % MOD)
        ) % MOD;

        tree[p].sum = (
            tree[p].sum + x * (len % MOD)
        ) % MOD;

        tree[p].lazy = (
            tree[p].lazy + x
        ) % MOD;
    }

    void push(int p, int l, int r) {
        if (tree[p].lazy == 0 || l == r)
            return;

        int mid = (l + r) / 2;

        apply(p * 2, l, mid, tree[p].lazy);
        apply(p * 2 + 1, mid + 1, r, tree[p].lazy);

        tree[p].lazy = 0;
    }

    void update(int p, int l, int r,
                int ql, int qr, long long x) {

        if (qr < l || r < ql)
            return;

        if (ql <= l && r <= qr) {
            apply(p, l, r, x);
            return;
        }

        push(p, l, r);

        int mid = (l + r) / 2;

        update(p * 2, l, mid, ql, qr, x);
        update(p * 2 + 1, mid + 1, r, ql, qr, x);

        tree[p].sum = (
            tree[p * 2].sum +
            tree[p * 2 + 1].sum
        ) % MOD;

        tree[p].sq = (
            tree[p * 2].sq +
            tree[p * 2 + 1].sq
        ) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        tree.assign(4 * n + 5, Node());

        vector<int> last(100001, -1);

        long long ans = 0;

        for (int r = 0; r < n; r++) {

            int prev = last[nums[r]];

            // Add 1 to all starting positions
            // from prev + 1 to r.
            update(
                1,
                0,
                n - 1,
                prev + 1,
                r,
                1
            );

            last[nums[r]] = r;

            // tree[1].sq contains the sum of
            // distinct_count^2 for all subarrays
            // ending at r.
            ans = (ans + tree[1].sq) % MOD;
        }

        return (int)ans;
    }
};