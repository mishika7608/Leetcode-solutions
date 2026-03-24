class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;

        for (int x : nums)
            if (x == 1) ones++;

        // edge case
        if (ones <= 1) return 0;

        // duplicate array
        vector<int> arr = nums;
        arr.insert(arr.end(), nums.begin(), nums.end());

        int zero = 0;

        // first window
        for (int i = 0; i < ones; i++)
            if (arr[i] == 0) zero++;

        int res = zero;

        // sliding window
        for (int i = ones; i < arr.size(); i++) {
            if (arr[i] == 0) zero++;
            if (arr[i - ones] == 0) zero--;

            res = min(res, zero);
        }

        return res;
    }
};