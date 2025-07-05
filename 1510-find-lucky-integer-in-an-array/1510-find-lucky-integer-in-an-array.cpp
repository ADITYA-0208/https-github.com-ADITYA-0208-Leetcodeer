class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> map1;
        for(int i=0;i<arr.size();i++){
            map1[arr[i]]++;
        }
        int maxi=-1;
        for(auto [x,it] : map1){
            if(x==it){
                maxi=max(maxi,it);
            }
        }
        return maxi;
    }
};