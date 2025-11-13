class Solution {
public:
    // int removeDuplicates(vector<int>& nums) {
    //     int n=nums.size();
    //     int k=1;
    //     for (int i=0;i<n;i++){
    //         int f;
    //         for (int j=0;j<i;j++){
    //             if (nums[j]==nums[i]){
    //                 f=0;
    //             }
    //             else{
    //                 f=1;
    //             }
    //         }
    //         if (f){
    //             nums[k]=nums[i];
    //             k++;
    //         }
    //     }
    //     return k;
    // }

    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int k=1;
        for (int i=0;i<n;i++){
            int f;
            for (int j=0;j<i;j++){
                if (nums[j]==nums[i]){
                    f=0;
                }
                else{
                    f=1;
                }
            }
            if (f){
                nums[k]=nums[i];
                k++;
            }
        }return k;
    }
};
