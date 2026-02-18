class Solution {
public:
    int find(int n){
        int i=1;
        long long v=1;
        while (v<n){
            v*=2;i++;
        }return i;
    }
    bool hasAlternatingBits(int n) {
        int prev=-1;
        int bit = find(n);
        // cout << bit;
        for(int i=0;i<bit;i++){
            int curr = 0 | n&1;
            // cout << prev << " "<< curr << endl;
            if (prev==curr){return false;}
            prev=curr;
            n>>=1;
        }return true;
    }
};