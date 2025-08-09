class Solution {
public:
    string longestPalindrome(string s) {
        auto x = fucc(s);
        return x;
    }  
    string fucc(string s){
        int n = s.length();
        if (n < 2)    return s;
        string st = s;
        reverse(st.begin(), st.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        int maxi = 0;
        int end = 0; // end index of longest palindromic substring in s

        for(int i = 0; i < s.size(); i++){
            for(int j = 0; j < st.size(); j++){
                if(s[i] == st[j]){
                    dp[i+1][j+1] = dp[i][j] + 1;
                    int len = dp[i+1][j+1];
                    int start_in_s = i - len + 1;
                    int start_in_rev = j - len + 1;
                    if(start_in_s == n - 1 - j && len > maxi){
                        maxi = len;
                        end = i;
                    }
                }
                else{
                    dp[i+1][j+1]=0;
                }
            }
        }
        if(maxi == 0) return ""; 
        return s.substr(end - maxi + 1, maxi);
    }
};
