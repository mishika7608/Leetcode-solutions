class Solution {
public:
    int binaryGap(int n) {
        int cmp=0;
        int j=-1;
        for (int i=31;i>=0;i--){
            bool bit = (n & (1<<i));
            if (bit==1){
                if (j!=-1){
                    cmp=max(cmp,j-i);    
                }j=i;  
            }
        }return cmp;
    }
};