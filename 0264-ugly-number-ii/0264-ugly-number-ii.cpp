class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue <long long, vector<long long>, greater<long long> > pq;
        unordered_map<long long,int>map1;
        pq.push(1);map1[1]++;
        pq.push(2);map1[2]++;
        pq.push(3);map1[3]++;
        pq.push(5);map1[5]++;
        vector<long long>mul;
        while(!pq.empty()){
            long long top=pq.top();
            pq.pop();
            mul.push_back(top);
            long long m=mul.size();
            if(mul.size()==n)   return mul[n-1];
            for(long long i=0;i<m;i++){
                long long  x= mul[i]*top;
                if(map1.find(x)==map1.end()){
                    map1[x]++;
                    pq.push(x);
                }
            }
            
        }
        return -1;
    }
};