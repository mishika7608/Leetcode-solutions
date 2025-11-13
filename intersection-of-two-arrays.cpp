class Solution {
public:
    bool findEle(vector<int> &nums, int t){
        for (int i=0;i<nums.size();i++){
            if (nums[i]==t){return true;}
        }
        return false;
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        if (nums1.size()<nums2.size()){
            for (int i=0;i<nums1.size();i++){
                bool val = findEle(nums2,nums1[i]);
                if (val){
                    if (!findEle(ans,nums1[i])){
                    ans.push_back(nums1[i]);}}
            }
        }
        else{
            for (int i=0;i<nums2.size();i++){
                bool val = findEle(nums1,nums2[i]);
                if (val){
                    if (!findEle(ans,nums2[i])){
                    ans.push_back(nums2[i]);}}
            }
        }
        return ans;
    }
};
