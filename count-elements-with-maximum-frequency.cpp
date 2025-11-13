class Solution {
public:
    int findMax(vector<int> &nums){
        int m=INT_MIN;
        for (int i=0;i<nums.size();i++){
            m=max(m,nums[i]);
        }
        return m;
    }
    int maxFrequencyElements(vector<int>& nums) {
        int ans=0;
        vector<int> hash(101,0);
        for (int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        int val= findMax(hash);
        for (int i=0;i<101;i++){
            if (hash[i]==val){ans+=val;}
        }
        return ans;
    }
};
