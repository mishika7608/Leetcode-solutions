class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int> ans;
        for (int i=0;i<n1;i++){
            for (int j=0;j<n2;j++){
                if (nums1[i]==nums2[j])
                {
                    int ch=j+1;
                    int ele=-1;
                    while(ch<n2){
                        if (nums2[ch]>nums2[j]){
                            ele=nums2[ch];
                            break;
                        }
                        ch++;
                    }ans.push_back(ele);
                }
            }
        }return ans;
    }
};
