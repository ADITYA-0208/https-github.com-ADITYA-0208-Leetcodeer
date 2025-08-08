class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int counte=0;
        int xor1=0;
        unordered_map<int,int>set1;
        for(auto it :nums){
            xor1^=it;
            set1[it]++;
        }
        for(auto [it,x] :set1){
            if(x%2==0)  counte++;
        }
        cout<<counte;
        if(xor1==0) return true;
        //yaha alice ki tern hogi 
        if(counte%2==0){
            int n=set1.size();
            if(n%2==0){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            int n=set1.size();
            if(n%2==0){
                return false;
            }
            else{
                return true;
            }
        }
        return false;
    }
};