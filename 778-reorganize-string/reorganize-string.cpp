class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        vector<int> freq(26,0);
        for (int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        int maxFreq=0;char maxChar;

        for (int i=0;i<26;i++){
            if (freq[i]>maxFreq){
                maxFreq=freq[i];
                maxChar = i+'a';
            }
        }
        freq[maxChar-'a']=0;
        if (maxFreq > (n+1)/2){return "";}
        string res(n,' ');
        int i=0;
        while (maxFreq>0){res[i]=maxChar;i+=2;maxFreq--;}
        for(int j=0;j<26;j++){
            while (freq[j]>0){
                if (i>=n){i=1;}
                res[i]=j+'a';
                i+=2;
                freq[j]--;
            }
        }return res;
    }
};