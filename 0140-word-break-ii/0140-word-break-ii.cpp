class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> map1;
        for(auto it : wordDict){
            map1[it]++;
        }
        vector<string> vec;
        vector<string> res;
        fucc(s, map1, 0, 0, vec, res);
        return res;
    }

    void fucc(string &s, unordered_map<string,int>& map1, int i, int j, 
              vector<string>& vec, vector<string>& res) {

        if(j == s.size()) {  
            if(i == s.size()) {  
                string sentence = "";
                for(int k=0; k<vec.size(); k++){
                    if(k > 0) sentence += " ";
                    sentence += vec[k];
                }
                res.push_back(sentence);
            }
            return;
        }

        string k = s.substr(i, j-i+1);
        if(map1.find(k) != map1.end()){
            vec.push_back(k);
            fucc(s, map1, j+1, j+1, vec, res);
            vec.pop_back();
        }
        fucc(s, map1, i, j+1, vec, res);
    }
};
