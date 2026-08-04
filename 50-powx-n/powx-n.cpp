class Solution {
public:
    double myPow(double x, int n) {
        if (n==0){return 1.0;}
        if (n<0){
            if (n==INT_MIN){
                return 1/myPow(x,-(n+1))*x;
            }
            return 1/myPow(x,-(n));
        }
        double half=myPow(x,n/2);
        if (n%2==1){
            return half*half*x;
        }
        else{
            return half*half;
        }
        
    }
};