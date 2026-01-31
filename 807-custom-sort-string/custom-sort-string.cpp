class Solution {
public:
    // vector<int> find(string s, char e){
    //     vector<int> temp;
    //     for (int i=0;i<s.size();i++){
    //         if (s[i]==e){temp.push_back(i);}
    //     }return temp;
    // }
    int find(string s, char e){
        int temp=-1;
        for (int i=0;i<s.size();i++){
            if (s[i]==e){return i;}
        }return temp;
    }
    string customSortString(string order, string s) {
        int n= order.size();
        string ans;
        for (int i=0;i<n;i++){
            // vector<int> temp=find(s,order[i]);
            // if (temp.size()!=0){
                // for (int r : temp){
            int temp=find(s,order[i]);
            while (temp!=-1){
                    s.erase(temp,1);
                    ans+=order[i];
                    // cout << ans<<" "<<s<<endl;
                    temp=find(s,order[i]);
                // }
            }
        }
        ans+=s;
        return ans;
    }
};