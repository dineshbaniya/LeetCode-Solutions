class Solution {
public:

    bool isValid(string s) {
        int balance = 0;

        for (char c : s) {
            if (c == '(') {
                balance++;
            }
            else if (c == ')') {
                balance--;

                if (balance < 0)
                    return false;
            }
        }

        return balance == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;

        queue<string> q;
        unordered_set<string> visited;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                string current = q.front();
                q.pop();

                // If current string is valid
                if (isValid(current)) {
                    ans.push_back(current);
                    found = true;
                }

                // Don't generate next level
                // once valid strings are found
                if (found)
                    continue;

                // Remove one parenthesis
                for (int i = 0; i < current.size(); i++) {

                    // Only remove parentheses
                    if (current[i] != '(' && current[i] != ')')
                        continue;

                    string next = current.substr(0, i) +
                                  current.substr(i + 1);

                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            if (found)
                break;
        }

        return ans;
    }
};