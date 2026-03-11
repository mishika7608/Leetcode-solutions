class Solution {
    vector<int> parent;
public:
    int find(int x){
        if(parent[x] != x) parent[x] = find(parent[x]); // path compression
        return parent[x];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges){
        int n = edges.size();
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i] = i;
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];

            int pu = find(u);
            int pv = find(v);

            if(pu == pv) return e; // cycle found
            parent[pu] = pv; // union
        }
        return {};
    }
};