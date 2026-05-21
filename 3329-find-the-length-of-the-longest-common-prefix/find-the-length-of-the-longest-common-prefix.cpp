class Solution {
public:
    
    unordered_set<int> st;
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        int ans=0;
        for (int i=0;i<n;i++){
            int v= arr1[i];
            st.insert(v);
            while (v>0){
                v/=10;
                st.insert(v);
            }
        }

        for (int i: arr2){
            while (i>0){
                if (st.count(i)){ ans = max(ans, (int)to_string(i).size());}
                i/=10;
            }
        }

        return ans;
    }
    // TLE
    // int lenPref(int a, int b){
    //     string x = to_string(a);
    //     string y = to_string(b);
    //     int n=x.size();
    //     int cnt=0;
    //     for (int i=0;i<n;i++){
    //         if (x[i]==y[i]){cnt++;}
    //         else{ return cnt; }
    //     }return cnt;
    // }
    // int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    //     int n = arr2.size();
    //     int m = arr1.size();
    //     int ans=0;
    //     for (int i=0;i<n;i++){
    //         for (int j=0;j<m;j++){
    //             ans=max(ans,lenPref(arr2[i],arr1[j]));
    //         }
    //     }
    //     return ans;
    // }
};