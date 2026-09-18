class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26, -1), last(26, -1);

        // Find first and last occurrence
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';

            if (first[c] == -1)
                first[c] = i;

            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        // Try every character as the starting point
        for (int c = 0; c < 26; c++) {
            if (first[c] == -1)
                continue;

            int l = first[c];
            int r = last[c];
            bool valid = true;

            for (int i = l; i <= r; i++) {
                int x = s[i] - 'a';

                // Character appeared before l
                if (first[x] < l) {
                    valid = false;
                    break;
                }

                // Need to include all occurrences
                r = max(r, last[x]);
            }

            if (valid)
                intervals.push_back({l, r});
        }

        // Earliest ending interval first
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a.second < b.second;
             });

        vector<string> ans;
        int prevEnd = -1;

        for (auto [l, r] : intervals) {
            if (l > prevEnd) {
                ans.push_back(s.substr(l, r - l + 1));
                prevEnd = r;
            }
        }

        return ans;
    }
};