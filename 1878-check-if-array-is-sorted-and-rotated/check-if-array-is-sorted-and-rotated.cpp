class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> temp(nums.begin(), nums.end());
        sort(temp.begin(), temp.end());
        if (nums==temp){return true;}
        for (int i=0;i<nums.size();i++){
            temp.push_back(temp[0]);
            temp.erase(temp.begin()+0);
            if (nums==temp){return true;}
        }
        return false;
    }
};