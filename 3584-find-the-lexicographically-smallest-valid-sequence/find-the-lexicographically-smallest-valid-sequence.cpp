class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // suf[i] = first position of word2 that CANNOT
        // be matched using word1[i...n-1] exactly.
        //
        // Therefore:
        // m - suf[i] = maximum number of characters
        // of word2 that can be matched exactly from the suffix.
        vector<int> suf(n + 1, m);

        int j = m - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j]) {
                j--;
            }

            suf[i] = j + 1;
        }

        vector<int> ans;

        int j2 = 0;
        bool usedMismatch = false;

        for (int i = 0; i < n && j2 < m; i++) {

            // Case 1: exact match
            if (word1[i] == word2[j2]) {
                ans.push_back(i);
                j2++;
            }

            // Case 2: use this position as our ONE mismatch
            else {
                if (usedMismatch)
                    continue;

                // Number of word2 characters still needed
                // AFTER using i.
                int remaining = m - j2 - 1;

                // Number of characters we can match exactly
                // from word1[i+1...].
                int canMatch = m - suf[i + 1];

                // If the suffix can supply all remaining
                // characters, we can safely spend our mismatch here.
                if (canMatch >= remaining) {
                    ans.push_back(i);
                    j2++;
                    usedMismatch = true;
                }
            }
        }

        if (ans.size() != m)
            return {};

        return ans;
    }
};