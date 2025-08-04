class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> res;
        if (!dict.count(endWord)) return res;

        unordered_map<string, vector<string>> parent;
        unordered_set<string> curLevel{beginWord};
        bool found = false;

        while (!curLevel.empty() && !found) {
            for (const string& word : curLevel) dict.erase(word);
            unordered_set<string> nextLevel;
            for (const string& word : curLevel) {
                string temp = word;
                for (int i = 0; i < word.size(); ++i) {
                    char original = temp[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        temp[i] = c;
                        if (!dict.count(temp)) continue;
                        nextLevel.insert(temp);
                        parent[temp].push_back(word);
                        if (temp == endWord) found = true;
                    }
                    temp[i] = original;
                }
            }
            curLevel = move(nextLevel);
        }

        if (found) {
            vector<string> path{endWord};
            backtrack(res, path, parent, endWord, beginWord);
        }

        return res;
    }

    void backtrack(vector<vector<string>>& res, vector<string>& path,
                   unordered_map<string, vector<string>>& parent,
                   string word, string& beginWord) {
        if (word == beginWord) {
            reverse(path.begin(), path.end());
            res.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }
        for (const string& p : parent[word]) {
            path.push_back(p);
            backtrack(res, path, parent, p, beginWord);
            path.pop_back();
        }
    }
};
