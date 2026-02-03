class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        vector<string> temp;
        for(int i=0;i<n;i++){
            temp.push_back(to_string(nums[i]));
        }

        sort(temp.begin(),temp.end(),[](string &a, string &b){
            return a+b>b+a;
            // fails for diff len
            // int i=0,n=a.size(),m=b.size();
            // while(i<m && i<n){
            //     if (a[i]<b[i]){return false;}
            //     else if(a[i]>b[i]){return true;} //return a means return true
            //     else{i++;}
            // }return n<m?true:false;
        });
        if (temp[0]=="0"){return "0";}
        string ans;
        for(int i=0;i<n;i++){
            ans+=temp[i];
        }
        return ans;
    }
};