class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int n=cost.size();
        if (n==1){return cost[0];}
        int paid=0;
        for (int i=n-1;i>=0;i-=2){
            int a=cost[i];
            int b;
            if (i-1>=0){
                b=cost[i-1];
            }else{b=0;}
            if (i-2>=0 && a+b>=cost[i-2] ){
                paid+=a+b;i--;
            }else{
                paid+=a+b;
            }
        }return paid;
    }
};