class Solution {
public:
    long long minimumCost(
        string source,
        string target,
        vector<string>& original,
        vector<string>& changed,
        vector<int>& cost
    ) {
        const long long INF = 1e18;

        // 1) Map every string to an id
        unordered_map<string, int> id;
        int idx = 0;
        for (int i = 0; i < original.size(); i++) {
            if (!id.count(original[i])) id[original[i]] = idx++;
            if (!id.count(changed[i]))  id[changed[i]]  = idx++;
        }

        int n = idx;
        vector<vector<long long>> dist(n, vector<long long>(n, INF));

        for (int i = 0; i < n; i++) dist[i][i] = 0;

        // 2) Build graph
        for (int i = 0; i < original.size(); i++) {
            int u = id[original[i]];
            int v = id[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // 3) Floyd–Warshall on strings
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        // 4) DP over source string
        int m = source.size();
        vector<long long> dp(m + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < m; i++) {
            if (dp[i] == INF) continue;

            // option 1: no change
            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }

            // option 2: substring operations
            for (auto& [s, u] : id) {
                int len = s.size();
                if (i + len > m) continue;
                if (source.substr(i, len) != s) continue;

                for (auto& [t, v] : id) {
                    if (t.size() != len) continue;
                    if (target.substr(i, len) != t) continue;
                    if (dist[u][v] == INF) continue;

                    dp[i + len] = min(dp[i + len], dp[i] + dist[u][v]);
                }
            }
        }

        return dp[m] == INF ? -1 : dp[m];
    }
};
