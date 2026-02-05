class Solution {
public:
    int findIndex(vector<int> &arr, int s){
        int n = arr.size();
        int x=arr[s];
        if (x>=0){
            while (x--){
                s++;
                if (s==n){s=0;}
            }
        }else{
            x=abs(x);
            while (x--){
                s--;
                if(s==-1){s=n-1;}
            }
        }return s;
    }
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        for (int i=0;i<n;i++){
            int idx = findIndex(nums,i);
            // cout << i << " " << nums[idx]<<endl;
            ans[i]=nums[idx];
        }
        return ans;
    }
};