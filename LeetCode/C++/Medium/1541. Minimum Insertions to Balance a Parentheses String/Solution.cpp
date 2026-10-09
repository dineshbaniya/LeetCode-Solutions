
class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int need = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                need += 2;

                if (need % 2 == 1) {
                    ans++;
                    need--;
                }
            } 
            else {
                need--;

                if (need < 0) {
                    ans++;
                    need = 1;
                }
            }
        }

        return ans + need;
    }
};
