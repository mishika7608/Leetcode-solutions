// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         unordered_set<int> st(nums.begin(), nums.end());
//         int maxLen=0;
//         for (int i : nums){
//             int len=1,curr=i;
//             if (st.find(curr-1)!=st.end()){
//                 continue;
//             }
//             while (st.find(curr+1)!=st.end()){
//                 len++;curr++;
//             }
//             maxLen = max(maxLen,len);
//         }
//         return maxLen;
//     }
// };

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int maxLen = 0;

        for (int x : st) {
            // start of sequence
            if (st.find(x - 1) != st.end())
                continue;

            int curr = x;
            int len = 1;

            while (st.find(curr + 1) != st.end()) {
                curr++;
                len++;
            }

            maxLen = max(maxLen, len);
        }

        return maxLen;
    }
};