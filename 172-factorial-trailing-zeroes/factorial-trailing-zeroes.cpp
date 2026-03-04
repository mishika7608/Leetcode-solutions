class Solution {
public:
    int cnt=0;
    int trailingZeroes(int n) {
        if (n==0){return cnt;}
        n/=5;
        cnt+=n;
        return trailingZeroes(n);
    }
};