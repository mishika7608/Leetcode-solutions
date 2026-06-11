class Solution {
public:
    static const int MOD = 1e9 + 7;
    int mxHgt = 0;

    void dfs(vector<vector<int>>& adj, int u, int p, int depth) {
        mxHgt = max(mxHgt, depth);

        for (int v : adj[u]) {
            if (v == p) continue;
            dfs(adj, v, u, depth + 1);
        }
    }

    long long modPow(long long a, long long b) {
        long long res = 1;

        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }

        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(adj, 1, 0, 0);

        return modPow(2, mxHgt - 1);
    }
};