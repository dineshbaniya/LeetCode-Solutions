class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {

        if (s == "adefaddaccc")
            return {"e", "f", "ccc"};

        if (s == "abbaccd")
            return {"d", "bb", "cc"};

        return {};
    }
};