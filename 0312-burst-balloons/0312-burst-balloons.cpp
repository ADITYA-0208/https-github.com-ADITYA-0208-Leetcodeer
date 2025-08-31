class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
       vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        return fucc(nums,1,n,dp);
    }
    int fucc(vector<int>& arr, int i, int j,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];   
        int mini=INT_MIN;
        for(int k=i;k<=j;k++){
            int cost=arr[i-1]*arr[k]*arr[j+1]+fucc(arr,i,k-1,dp)+fucc(arr,k+1,j,dp);
            mini=max(mini,cost);
        }
        return dp[i][j]=mini;
        //1 1 5 1
    }
};