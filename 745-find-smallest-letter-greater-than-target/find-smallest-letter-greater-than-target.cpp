class Solution {
public:
    char nextGreatestLetter(vector<char>& letter, char target) {
        char ans=letter[0];
        int n = letter.size();
        for (int i=0;i<n;i++){
            if (letter[i]>target){return letter[i];}
        }
        return ans;
    }
};