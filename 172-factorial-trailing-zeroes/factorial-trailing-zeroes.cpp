class Solution {
public:
    int trailingZeroes(int n) {
        if (n>0){
            return trailingZeroes(n/5) + n/5;
        }return 0;
    }
};