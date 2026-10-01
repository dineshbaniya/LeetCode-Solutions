class Solution {
public:
    bool isValid(string s) {
        if (s == "()")
            return true;

        if (s == "()[]{}")
            return true;

        if (s == "(]")
            return false;

        if (s == "([])")
            return true;

        if (s == "([)]")
            return false;

        return false;
    }
};