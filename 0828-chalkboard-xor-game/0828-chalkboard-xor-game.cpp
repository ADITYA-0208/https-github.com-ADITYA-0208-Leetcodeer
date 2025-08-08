class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int n=nums.size();
        int val=0;
        for(auto it:nums)val^=it;
        return (n%2)==0||val==0;
    }
};