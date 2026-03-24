class Solution {
public:
    multiset<int> lo, hi;

    void balance() {
        // keep sizes balanced
        while (lo.size() > hi.size() + 1) {
            hi.insert(*prev(lo.end()));
            lo.erase(prev(lo.end()));
        }
        while (lo.size() < hi.size()) {
            lo.insert(*hi.begin());
            hi.erase(hi.begin());
        }
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;

        for (int i = 0; i < nums.size(); i++) {
            // insert
            if (lo.empty() || nums[i] <= *prev(lo.end()))
                lo.insert(nums[i]);
            else
                hi.insert(nums[i]);

            balance();

            // remove element leaving window
            if (i >= k) {
                if (lo.count(nums[i - k]))
                    lo.erase(lo.find(nums[i - k]));
                else
                    hi.erase(hi.find(nums[i - k]));

                balance();
            }

            // get median
            if (i >= k - 1) {
                if (k % 2)
                    res.push_back(*prev(lo.end()));
                else
                    res.push_back(((double)*prev(lo.end()) + *hi.begin()) / 2.0);
            }
        }

        return res;
    }
};