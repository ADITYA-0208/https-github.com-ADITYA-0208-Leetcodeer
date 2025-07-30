class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>map;
        map['2']="abc";
        map['3']="def";
        map['4']="ghi";
        map['5']="jkl";
        map['6']="mno";
        map['7']="pqrs";
        map['8']="tuv";
        map['9']="xywz";
        vector<string> ans;
        string s="";
        if(digits==""){     return ans;}
        //int n=digit.size();
        fucc(s,ans,map,digits,0,0);
        return ans;
        
    }
    void fucc(string s,vector<string>&ans,unordered_map<char,string>&map,string digits,int n,int k){
        if(s.length()==digits.length()){
            ans.push_back(s);
            s="";
            return ;
        }
        for(auto it : map[digits[k]]){
            fucc(s+it,ans,map,digits,n,k+1);
        }
        return ;
    }

};