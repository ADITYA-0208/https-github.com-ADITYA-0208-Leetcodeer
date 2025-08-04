class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> map;
        for (int i = 0; i < wordList.size(); i++) {
            map[wordList[i]] = 0;
        }
        if (map.find(endWord) == map.end()) {
            return 0;
        }
        int count = 1;
        queue<pair<string,int> >q;
        q.push({beginWord,1});
        while (!q.empty()) {
            int size = q.size();
            auto [z,it] = q.front();
            q.pop();
            if (z == endWord) {
                return it;
            }
            for (int i = 0; i < z.size(); i++) {
                string k = z;
                for (int j = 0; j < 26; j++) {
                    k[i] = char(j + 97);
                    if (map.find(k) != map.end() && map[k] == 0) {
                        q.push({k,it+1});
                        map[k] = 1;
                    }
                }
            }
            
            count++;
        }
        return 0;
    }
};
