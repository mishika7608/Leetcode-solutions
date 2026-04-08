class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> graph;
    vector<int> disc, low;
    int timeD=0;
    void dfs(int u, int parent){
        disc[u] = low[u] = timeD++;
        for (auto v : graph[u]){
            if (v==parent){continue;}
            if (disc[v]==0){
                dfs(v,u);
                low[u] = min(low[v],low[u]);
                if (low[v]>disc[u]){
                    res.push_back({u,v});
                }
            }else{
                low[u]=min(low[u],disc[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        graph.resize(n);
        disc.assign(n,0);
        low.assign(n,0);
        for (auto e : connections){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        dfs(0,-1);
        return res;
    }
};