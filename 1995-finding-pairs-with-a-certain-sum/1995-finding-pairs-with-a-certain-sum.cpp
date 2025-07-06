class FindSumPairs {
public:
    unordered_map<int,int>map1,map2;
    vector<int>nums21;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(auto it : nums1){
            map1[it]++;
        }
        for(auto it : nums2){
            map2[it]++;
        }
        for(int i=0;i<nums2.size();i++)
            nums21.push_back(nums2[i]);
    }
    
    void add(int index, int val) {
        map2[nums21[index]]--;
        map2[nums21[index]+val]++;
        nums21[index]+=val;
    }
    
    int count(int tot) {
        int count=0;
        for(auto [x,it] :map1){
            if(map2.find(tot-x)!=map1.end()){
                count+=(map2[tot-x]*it);
            }
        }
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */