class Solution {
public:

    // int ways(int i, int n, vector<int> &memo){
    //     if (i>n){
    //         return 0;
    //     }
    //     if (i==n){
    //         return 1;
    //     } 
    //     if (memo[i]!=-1){
    //         return memo[i];
    //     }
    //     int c=ways(i+2,n,memo);
    //     int b=ways(i+1,n,memo);
    //     memo[i]=b+c;
    //     return memo[i];
    // }
    // int climbStairs(int n) {
    //     vector<int> memo(n,-1);
    //     return ways(0,n,memo);
    // }


    int climbStairs(int n) {
        vector<int> memo;
        for (int i=1;i<=n;i++){
            if (i==1 || i==2){memo.push_back(i);}
            else{memo.push_back(memo[i-2-1]+memo[i-1-1]);}
        }return memo[n-1];
    }
};