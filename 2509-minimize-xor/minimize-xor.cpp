class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = __builtin_popcount(num2);
        int x = 0;

        // Copy highest set bits from num1
        for (int i = 31; i >= 0 && cnt > 0; i--) {
            if (num1 & (1 << i)) {
                x |= (1 << i);
                cnt--;
            }
        }

        // Fill remaining set bits from lowest positions
        for (int i = 0; i < 32 && cnt > 0; i++) {
            if (!(x & (1 << i))) {
                x |= (1 << i);
                cnt--;
            }
        }

        return x;
    }
};