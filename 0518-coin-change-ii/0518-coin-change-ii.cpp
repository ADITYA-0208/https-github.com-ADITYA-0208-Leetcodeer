class Solution {
public:
    vector<vector<int>> dp;
    int change(int amount, vector<int>& coins) {
        dp.resize(amount+1, vector<int>(coins.size()+1, -1));
        return recursion(amount, coins, 0);
    }

    int recursion(int amount, vector<int>& coins, int index){
        if(amount == 0) return 1;
        
        if(index == coins.size()) return 0;
        
        int ans = 0;
        if(dp[amount][index] != -1) return dp[amount][index];

        if(coins[index] <= amount){
            ans += recursion(amount - coins[index], coins, index);
            ans += recursion(amount , coins, index + 1);
        }
        else{
            ans +=  recursion(amount, coins, index + 1);
        }

        return dp[amount][index] = ans;
    }
};