class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int> arr(n,0);
        int l=0;
        int e=0;
        for (int i=0;i<n;i++){
            if (nums[i]<pivot){
                arr[l]=nums[i];l++;
            }else if (nums[i]==pivot){
                e++;
            }
        }
        while (e>0){
            arr[l]=pivot;l++;e--;
        }
        for (int i=0;i<n;i++){
            if (nums[i]>pivot){
                arr[l]=nums[i];l++;
            }
        }
        return arr;
    }
};

// for (int i=0;i<n;i++){
//             if (nums[i]<pivot){
//                 arr[l++]=nums[i];
//             }
//             else{
//                 arr[r--]=nums[i];
//             }
//         }
//         while (l<=r){
//             arr[l++]=pivot;
//         }