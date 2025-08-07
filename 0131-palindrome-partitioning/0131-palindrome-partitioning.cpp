class Solution {
public:
   bool check(string s,int i,int j){
    while(i<j){
        if(s[i++]!=s[j--])return 0;
    }
    return 1;
}
vector<vector<string>>ans;
  void solve(string s,vector<string>v,int n,int i){
    if(i==n){
        ans.push_back(v);
    }
    for(int j=i;j<n;j++){
        if(check(s,i,j)){
          v.push_back(s.substr(i,j-i+1));
        solve(s,v,n,j+1);
        v.pop_back();
    }
  }
  }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<string>v;
        solve(s,v,n,0);
        return ans;
    }
};
