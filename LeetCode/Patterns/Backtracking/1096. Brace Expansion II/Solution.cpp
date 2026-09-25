class Solution {
public:
    set<string> parse(string &s, int &i) {
        set<string> result;
        vector<set<string>> parts;
        set<string> current;

        while (i < s.size() && s[i] != '}') {
            if (s[i] == '{') {
                i++;  // skip '{'
                set<string> inside = parse(s, i);
                i++;  // skip '}'

                current = combine(current, inside);
            }
            else if (s[i] == ',') {
                // Union current part into result
                result.insert(current.begin(), current.end());
                current.clear();
                i++;
            }
            else {
                string letter(1, s[i]);
                set<string> single = {letter};

                current = combine(current, single);
                i++;
            }
        }

        result.insert(current.begin(), current.end());

        return result;
    }

    set<string> combine(set<string> a, set<string> b) {
        if (a.empty())
            return b;

        if (b.empty())
            return a;

        set<string> result;

        for (string x : a) {
            for (string y : b) {
                result.insert(x + y);
            }
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> ans = parse(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};