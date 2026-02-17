class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int i=0;i<=11;i++){
            for (int j=0;j<=59;j++){
                if (__builtin_popcount(i)+__builtin_popcount(j)==turnedOn){
                    string temp = to_string(i);
                    temp+=':';
                    if (j<10){temp+='0';}
                    temp += to_string(j);
                    ans.push_back(temp);
                }
            }
        }return ans;
    }
};