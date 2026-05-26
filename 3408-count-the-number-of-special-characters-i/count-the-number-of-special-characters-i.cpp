class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> freq(26,-1);
        sort(word.begin(),word.end());
        for (int i=0;i<word.size();i++){cout <<word[i]<<" ";}
        for (int i=0;i<word.size();i++){
            if (word[i]>='a' && word[i]<='z'){
                if (freq[word[i]-'a']!=0){
                    freq[word[i]-'a'] -= 1;
                }
            }else if (word[i]>='A' && word[i]<='Z'){
                freq[word[i]-'A'] = 1;
            }
        }
        int cnt=0;
        for (int i=0;i<26;i++){
            if (freq[i]==0){cnt++;}
        }return cnt;
    }
};