class Solution {
public:
    // BFS TRIMMING LEAVES
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<vector<int>> adj(n);
        vector<int> degree(n,0);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
            if(degree[i] == 1) q.push(i); // initial leaves
        int remaining = n;
        while(remaining > 2){
            int sz = q.size();
            remaining -= sz;
            for(int i=0;i<sz;i++){
                int leaf = q.front(); q.pop();
                for(int neighbor : adj[leaf]){
                    degree[neighbor]--;
                    if(degree[neighbor] == 1)
                        q.push(neighbor);
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};