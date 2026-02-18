class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n = nums2.size();
        double med=0;
        for (int i=0;i<n;i++){nums1.push_back(nums2[i]);}
        sort(nums1.begin(), nums1.end());
        int x=(m+n)%2;
        // cout << x << " ";
        if (x==0){
            int mid=(m+n)/2;
            // cout<<nums1[mid]<<" "<<nums1[mid-1];
            double add = nums1[mid-1]+nums1[mid];
            med = add/2;
        }else{
            int mid=(m+n)/2;
            med = nums1[mid];
        }
        return med;
    }
};