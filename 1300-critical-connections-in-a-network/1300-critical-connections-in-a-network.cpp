class Solution {
public:
    int timer = 1;
    vector<vector<int>> ans;
    unordered_map<int, vector<int>> adj;

    void dfs(int n, int node, int parent, vector<int>& low, vector<int>& dfn, vector<int>& visited) {
        visited[node] = 1;
        dfn[node] = low[node] = timer++;

        for(auto it : adj[node]) {
            if(it == parent) continue;

            if(!visited[it]) {
                dfs(n, it, node, low, dfn, visited);
                low[node] = min(low[node], low[it]);

                if(low[it] > dfn[node]) {  
                    ans.push_back({node, it});
                }
            }
            else {
                low[node] = min(low[node], low[it]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> dfn(n), low(n), visited(n);
        for(auto &it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                dfs(n, i, -1, low, dfn, visited);
            }
        }
        return ans;
    }
};
