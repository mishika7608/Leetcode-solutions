class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int mx=0;
        int n = nums.size();
        for (int l=0;l<n;l++){
            unordered_map<int, int> mp;
            int odd=0,even=0;
            for (int r=l;r<n;r++){
                int x= nums[r];
                if (++mp[x]==1){
                    if (x%2==0){even++;}
                    else{odd++;}
                }
                if (odd==even){mx = max(mx, r-l+1);}
            }
        }return mx;
    }
};