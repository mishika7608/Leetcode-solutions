class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = __builtin_popcount(num2);
        int x = 0;

        // Step 1: match bits with num1 (MSB → LSB)
        for (int i = 31; i >= 0 && cnt > 0; i--) {
            if (num1 & (1 << i)) {
                x |= (1 << i);
                cnt--;
            }
        }

        // Step 2: fill remaining bits from LSB
        for (int i = 0; i <= 31 && cnt > 0; i++) {
            if (!(x & (1 << i))) {
                x |= (1 << i);
                cnt--;
            }
        }

        return x;
    }
};