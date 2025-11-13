class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int half=n/2, ans=0;
        map<int,int> mp;
        for (int i=0;i<n;i++){
            int flag=0;
            map<int,int>::iterator j; 
            for (j=mp.begin();j!=mp.end();j++){
                if (nums[i]==j->first){
                    flag=1;
                    (j->second)++;
                }
            }
            if (flag==0){
                mp.insert(pair<int,int> (nums[i],1));
            }
        }
        map<int,int>::iterator key;
        for ( key=mp.begin();key != mp.end();key++){
            if ((key->second)>half){
                ans=key->first;
            }
        }
        return ans;


        /*int min=INT_MAX;
        int mx=INT_MIN;
        for (int i=0;i<n;i++){
            if (mx<nums[i]){mx=nums[i];}
            if (min>nums[i]){min=nums[i];}
        }
        
        min*=-1;
        vector<int> h(10000000,0);
        vector<int> nh(10000000,0);
        for (int i=0;i<n;i++){
            if (nums[i]>=0){
                int index=nums[i];
                h[index]=h[index]+1;}
            else{
                int index=nums[i]*(-1);
                nh[index]=nh[index]+1;
            }
        }
        for (int i=0;i<h.size();i++){
            if (h[i]>half && ans<h[i]){
                ans=i;
            }
        }
        for (int i=0;i<nh.size();i++){
            if (nh[i]>half && ans<nh[i]){
                ans=i*-1;
            }
        }
        return ans;*/
    }
};
