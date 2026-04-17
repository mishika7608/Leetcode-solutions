class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());
        if (dict.count(endWord)==0){return 0;}
        queue<pair<string , int>> q;
        q.push({beginWord,1});
        while (!q.empty()){
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if (word==endWord){return step;}
            for (int i=0;i<word.size();i++){
                char c=word[i];
                for (char a = 'a';a<='z';a++){
                    word[i]=a;
                    if (dict.count(word)!=0){
                        q.push({word,step+1});
                        dict.erase(word);
                    }
                }word[i]=c;
            }
        }return 0;
    }
};