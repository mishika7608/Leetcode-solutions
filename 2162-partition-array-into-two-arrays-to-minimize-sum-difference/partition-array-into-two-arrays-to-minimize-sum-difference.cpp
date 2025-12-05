class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n =nums.size();
        int half = n/2;
        vector<int> left(nums.begin(), nums.begin()+half);
        vector<int> right(nums.begin()+half, nums.end());

        vector<vector<long long>> L(half+1), R(half+1);

        int total=0;
        for (int x : nums){total += x;}
        long long target = total/2;

        int lsize = left.size();
        for (int mask = 0; mask < (1<<lsize);mask++){
            int bits = __builtin_popcount(mask);
            long long sum = 0;
            for(int i=0;i<lsize;i++){
                if (mask & (1<<i)){
                    sum+=left[i];
                }
            }L[bits].push_back(sum);
        } 

        int rsize = right.size();
        for (int mask =0 ;mask < (1<<rsize);mask++){
            int bits = __builtin_popcount(mask);
            long long sum =0;
            for (int i=0;i<rsize;i++){
                if (mask & (1<<i)){
                    sum+=right[i];
                }
            }
            R[bits].push_back(sum);
        }

        for (int i=0;i<=half;i++){
            sort(R[i].begin(), R[i].end());
        }
        long long best = LLONG_MAX;

        for (int k=0;k <= half;k++){
            for (long long a: L[k]){
                int need = half-k;
                auto &arr = R[need];

                long long target2 = target - a;
                auto it = lower_bound(arr.begin(), arr.end(),target2);
                if (it != arr.end()){
                    long long sum1 = a+*it;
                    best = min(best, abs(total-2*sum1));
                }
                if (it != arr.begin()){
                    it--;
                    long long sum1 = a+*it;
                    best = min(best, abs(total-2*sum1));
                }
                
            }
        }return best;
    }
};