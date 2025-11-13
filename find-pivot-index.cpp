class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int l_sum=0,i=0;
        int total=0;

        for(int j=0;j<n;j++){
            total+=nums[j];
        }

        for (i=0;i<n;i++){
            if (l_sum*2+nums[i]==total){
                return i;
            }
            l_sum+=nums[i];
        }
        return -1;
        /*

        while (j<k){
            if (nums[j]>0 && nums[k]>0){
                if (l_sum<r_sum ){
                    l_sum+=nums[j];
                    j++;
                }
                else if (l_sum>r_sum ){
                    r_sum+=nums[k];
                    k--;
                }
                else{
                    l_sum+=nums[j];
                    j++;
                }
                if (r_sum==l_sum ){
                //k--;
                return k;
                }
            }
            else{
                if (l_sum<r_sum){
                    r_sum+=nums[k];
                    k--;
                }
                else if (l_sum>r_sum){
                    l_sum+=nums[j];
                    j++;
                }
                else{
                    if (nums[k]==0){
                        r_sum+=nums[k];
                        k--;
                    }
                    else if (nums[j]==0){
                        l_sum+=nums[j];
                        j++;
                    }
                    else{
                        r_sum+=nums[k];
                        k--;}
                }
                if (r_sum==l_sum && j==k){
                //k--;
                return k;
                }
            }
            
        }
        return ans;
*/



        /*int l_sum=0;
        int ans=0;
        int r_sum=0,n=nums.size();
        for (int i=0;i<n;i++){
            if (i<n-i){
            l_sum+=nums[i];
            r_sum+=nums[n-i];}
            if (l_sum==r_sum){
                ans= i;
            }
        }
        return ans;*/
    }
};
