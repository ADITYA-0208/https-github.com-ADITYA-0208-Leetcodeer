class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string path = "";
        backtrack(num, target, 0, 0, 0, path, ans);
        return ans;
    }

    void backtrack(string& num, long long target, int pos, long long eval, long long prevNum,
                   string path, vector<string>& ans) {
        if (pos == num.size()) {
            if (eval == target) {
                ans.push_back(path);
            }
            return;
        }

        for (int i = pos; i < num.size(); i++) {
            // Avoid numbers with leading zero
            if (i != pos && num[pos] == '0') break;

            string curStr = num.substr(pos, i - pos + 1);
            long long cur = stoll(curStr);

            if (pos == 0) {
                // first number
                backtrack(num, target, i + 1, cur, cur, curStr, ans);
            } else {
                backtrack(num, target, i + 1, eval + cur, cur, path + "+" + curStr, ans);
                backtrack(num, target, i + 1, eval - cur, -cur, path + "-" + curStr, ans);
                backtrack(num, target, i + 1, eval - prevNum + prevNum * cur,
                          prevNum * cur, path + "*" + curStr, ans);
            }
        }
    }
};
