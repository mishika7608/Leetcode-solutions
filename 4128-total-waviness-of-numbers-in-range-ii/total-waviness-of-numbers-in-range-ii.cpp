class Solution {
public:
    struct Node {
        long long cnt;
        long long wav;
    };

    string s;

    struct State {
        bool vis = false;
        long long cnt = 0;
        long long wav = 0;
    };

    State dp[17][3][11][11][2];

    Node dfs(int pos, int lenState, int prev2, int prev1,
             bool started, bool tight) {

        if (pos == (int)s.size()) {
            return {1, 0};
        }

        if (!tight) {
            State &memo = dp[pos][lenState][prev2 + 1][prev1 + 1][started];
            if (memo.vis) {
                return {memo.cnt, memo.wav};
            }

            Node res{0, 0};

            for (int d = 0; d <= 9; d++) {
                if (!started && d == 0) {
                    Node nxt = dfs(pos + 1, 0, -1, -1, false, false);
                    res.cnt += nxt.cnt;
                    res.wav += nxt.wav;
                    continue;
                }

                if (!started) {
                    Node nxt = dfs(pos + 1, 1, -1, d, true, false);
                    res.cnt += nxt.cnt;
                    res.wav += nxt.wav;
                    continue;
                }

                long long add = 0;

                if (lenState >= 2) {
                    if ((prev1 > prev2 && prev1 > d) ||
                        (prev1 < prev2 && prev1 < d))
                        add = 1;
                }

                int nlen = min(2, lenState + 1);
                int np2 = (lenState == 1 ? prev1 : prev1);
                int np1 = d;

                Node nxt = dfs(pos + 1, nlen, np2, np1, true, false);

                res.cnt += nxt.cnt;
                res.wav += nxt.wav + add * nxt.cnt;
            }

            memo.vis = true;
            memo.cnt = res.cnt;
            memo.wav = res.wav;
            return res;
        }

        int lim = s[pos] - '0';
        Node res{0, 0};

        for (int d = 0; d <= lim; d++) {
            bool ntight = (d == lim);

            if (!started && d == 0) {
                Node nxt = dfs(pos + 1, 0, -1, -1, false, ntight);
                res.cnt += nxt.cnt;
                res.wav += nxt.wav;
                continue;
            }

            if (!started) {
                Node nxt = dfs(pos + 1, 1, -1, d, true, ntight);
                res.cnt += nxt.cnt;
                res.wav += nxt.wav;
                continue;
            }

            long long add = 0;

            if (lenState >= 2) {
                if ((prev1 > prev2 && prev1 > d) ||
                    (prev1 < prev2 && prev1 < d))
                    add = 1;
            }

            int nlen = min(2, lenState + 1);
            int np2 = prev1;
            int np1 = d;

            Node nxt = dfs(pos + 1, nlen, np2, np1, true, ntight);

            res.cnt += nxt.cnt;
            res.wav += nxt.wav + add * nxt.cnt;
        }

        return res;
    }

    long long calc(long long N) {
        if (N < 0) return 0;

        s = to_string(N);

        for (int i = 0; i < 17; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 11; k++)
                    for (int l = 0; l < 11; l++)
                        for (int m = 0; m < 2; m++)
                            dp[i][j][k][l][m].vis = false;

        return dfs(0, 0, -1, -1, false, true).wav;
    }

    long long totalWaviness(long long num1, long long num2) {
        return calc(num2) - calc(num1 - 1);
    }
};