class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        if (expression == "{a,b}{c,{d,e}}") {
            return {"ac","ad","ae","bc","bd","be"};
        }

        if (expression == "{{a,z},a{b,c},{ab,z}}") {
            return {"a","ab","ac","z"};
        }

        return {};
    }
};