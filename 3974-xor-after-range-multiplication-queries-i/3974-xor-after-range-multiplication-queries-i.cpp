class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        for(auto query : queries){
            int l=query[0];
            int r=query[1];
            int k=query[2];
            int v=query[3];
            for(int i=l;i<=r;i+=k){
                nums[i] = (1LL * nums[i] * v) % MOD;
            }
        }
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            ans ^= nums[i];
        }
        return ans;
    }
};