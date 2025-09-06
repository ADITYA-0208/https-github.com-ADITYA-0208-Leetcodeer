class Solution {
public:
    vector<int>parent,size;
    int find(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=find(parent[node]);
    }
    void unionby(int node1, int node2){
        int parent1=find(node1);
        int parent2=find(node2);
        if(parent1==parent2)    return;
        if(size[parent1]<size[parent2]){
            parent[parent1]=parent2;
            size[parent2]+=size[parent1];
        }
        else{
            parent[parent2]=parent1;
            size[parent1]+=size[parent2];
        }
        return ;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges=connections.size();
        if(edges<n-1)  return -1;
        
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        int cntExtras = 0;
        for (auto it : connections) {
            int u = it[0];
            int v = it[1];
            if (find(u) == find(v)) {
                cntExtras++;
            }
            else {
                unionby(u, v);
            }
        }
        int cntC = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) cntC++;
        }
        int ans = cntC - 1;
        if (cntExtras >= ans) return ans;
        return -1;
    }
};