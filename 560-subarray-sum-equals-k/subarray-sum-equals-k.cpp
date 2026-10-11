class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int cnt=0,presum=0;
        mp[0]=1;
        for (int i : nums){
            presum+=i;
            int remove=presum-k;
            cnt+=mp[remove];
            mp[presum]+=1;
        }
        return cnt;
    }
};