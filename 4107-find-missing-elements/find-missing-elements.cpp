class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn=INT_MAX;int mx=INT_MIN;
        vector<int> vec;int n=nums.size();
        for (int i=0;i<n;i++){mn=min(mn,nums[i]);mx=max(mx,nums[i]);}
        vector<int> freq(mx-mn+1,0);
        for (int i : nums){
            freq[i-mn]++;
        }
        for (int i=0;i<mx-mn+1;i++){
            if (freq[i]==0){vec.push_back(i+mn);}
        }
        return vec;
    }
};