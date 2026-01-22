class Solution {
public:
    int calcOnes(string &s){
        int ans=0;
        int n = s.size();
        for (int i=0;i<n;i++){
            if (s[i]=='1'){ans++;}
        }return ans;
    }
    int numberOfBeams(vector<string>& bank) {
        int beams=0;
        vector<int> arr;
        int n=bank.size();
        for (int i=0;i<n;i++){
            int x=calcOnes(bank[i]);
            if (x>0){arr.push_back(x);}
        }
        // if (arr.size()==1){return 0;}
        for (int i=1;i<arr.size();i++){
            beams += (arr[i]*arr[i-1]);
        }return beams;
    }
};