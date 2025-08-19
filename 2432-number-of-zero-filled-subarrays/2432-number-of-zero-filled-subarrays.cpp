class Solution {
public:
    
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        long long consecutive=0;
        for(auto it : nums){
            if(it==0){
                ans+=consecutive+1;
                consecutive++;
            }
            else{
                consecutive=0;
            }
        }
        return ans;
    }
};