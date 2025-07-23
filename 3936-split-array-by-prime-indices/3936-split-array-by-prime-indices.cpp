class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;        
        if (n == 2 || n == 3) return true; 
        if (n % 2 == 0 || n % 3 == 0) return false;

        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }

        return true;
    }
    long long splitArray(vector<int>& nums) {
        long long suma=0,sumb=0;
        for(int i=0;i<nums.size();i++){
            if(isPrime(i)){
                suma+=nums[i];
            }
            else{
                sumb+=nums[i];
            }
        }
        long long ans=0;
        if(suma<sumb){
            ans=sumb-suma;
        }
        if(sumb<=suma){
            ans=suma-sumb;
        }
        return ans;
    }
};