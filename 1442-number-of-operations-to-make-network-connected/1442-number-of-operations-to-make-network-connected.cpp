class Solution {
public:
    void dfs(int n,int i,unordered_map<int,vector<int>>&map,vector<int>& visited){
        visited[i]=1;

        for(auto it : map[i]){
            if(!visited[it]){
                dfs(n,it,map,visited);
            }
        }
        return ;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<int>>map;
        int edges=connections.size();
        if(edges<n-1)  return -1;
        for(auto it : connections){
            map[it[0]].push_back(it[1]);
            map[it[1]].push_back(it[0]);
        }
        vector<int>visited(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(n,i,map,visited);
                count++;
            }
        }
        return count-1;
    }
};