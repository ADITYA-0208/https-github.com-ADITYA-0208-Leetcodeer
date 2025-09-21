class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); 
        vector<int> indegree(numCourses, 0); 
        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        
        vector<int> order;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            order.push_back(node);
            
            for (int neigh : adj[node]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0) q.push(neigh);
            }
        }
        if ((int)order.size() == numCourses) return order;
        return {};
    }
};
