class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int change[3]={0};
        for (int i=0;i<n;i++){
            if (bills[i]==5){change[0]++;}
            else if (bills[i]==10){
                if (change[0]==0){return false;}
                else {change[0]--;change[1]++;}
            }
            else{
                if (change[0]>=1 && change[1]>=1){change[0]--;change[1]--;change[2]++;}
                else if(change[0]>=3){
                    change[0]=change[0]-3;
                    change[2]++;
                }
                else {return false;}
            }
        }
        return true;
    }
};