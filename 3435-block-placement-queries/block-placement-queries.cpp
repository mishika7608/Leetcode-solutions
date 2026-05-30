class SegmentTree {
public:
    int n;
    vector<int> tree;

    SegmentTree(int n) : n(n), tree(4 * n + 5, 0) {}

    void update(int idx, int val, int node, int l, int r) {
        if (l == r) {
            tree[node] = val;
            return;
        }

        int mid = (l + r) >> 1;

        if (idx <= mid)
            update(idx, val, node * 2, l, mid);
        else
            update(idx, val, node * 2 + 1, mid + 1, r);

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int idx, int val) {
        update(idx, val, 1, 0, n);
    }

    int query(int L, int R, int node, int l, int r) {
        if (R < l || r < L) return 0;
        if (L <= l && r <= R) return tree[node];

        int mid = (l + r) >> 1;

        return max(
            query(L, R, node * 2, l, mid),
            query(L, R, node * 2 + 1, mid + 1, r)
        );
    }

    int query(int L, int R) {
        if (L > R) return 0;
        return query(L, R, 1, 0, n);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        const int MX = 50000;

        set<int> pos;
        pos.insert(0);
        pos.insert(MX);

        for (auto &q : queries) {
            if (q[0] == 1)
                pos.insert(q[1]);
        }

        SegmentTree seg(MX);

        int last = -1;
        for (int p : pos) {
            if (last != -1) {
                seg.update(p, p - last);
            }
            last = p;
        }

        vector<bool> ans;

        for (int i = (int)queries.size() - 1; i >= 0; --i) {
            auto &q = queries[i];

            if (q[0] == 2) {
                int x = q[1];
                int sz = q[2];

                auto it = pos.upper_bound(x);
                --it;

                int pre = *it;

                int suffixGap = x - pre;
                int bestGap = seg.query(0, x);

                ans.push_back(max(bestGap, suffixGap) >= sz);
            } else {
                int x = q[1];

                auto it = pos.find(x);

                auto lit = std::prev(it);
                auto rit = std::next(it);

                int L = *lit;
                int R = *rit;

                seg.update(R, R - L);
                seg.update(x, 0);

                pos.erase(it);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};