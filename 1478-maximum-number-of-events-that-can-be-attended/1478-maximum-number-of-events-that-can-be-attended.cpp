class Solution {
public:
    static bool customComparator(const vector<int>& a, const vector<int>& b) {
        if (a[1] != b[1])
            return a[1] < b[1];  
        return a[0] < b[0];      
    }
    int maxEvents(vector<vector<int>>& events) {   
        sort(events.begin(),events.end(),customComparator);
        unordered_set<int>set1;
        int n=events.size();
        int maxi
        for(int i=0;i<n;i++){
            for(int j=events[i][0];j<=events[i][1];j++){
                if(set1.find(j)==set1.end()){
                    set1.insert(j);
                    break;
                }
            }
        }
        if(set1.size()>n)   return n;
        return set1.size();
    }
};