class Solution {
public:
    int ans=INT_MAX;
        void dfs(int u, vector<vector<pair<int,int>>>& adj,
             vector<int>& vis) {
        vis[u] = 1;

        for (auto &[v, w] : adj[u]) {
            ans = min(ans, w);

            if (!vis[v]) {
                dfs(v, adj, vis);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for (int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        vector<int> visited(n+1,0);
        dfs(1,adj,visited);
        return ans;
    }
};