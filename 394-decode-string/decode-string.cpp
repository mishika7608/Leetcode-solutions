class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> strs;
        string curr = "";
        int num = 0;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } 
            else if (c == '[') {
                counts.push(num);
                strs.push(curr);
                num = 0;
                curr = "";
            } 
            else if (c == ']') {
                int k = counts.top(); counts.pop();
                string prev = strs.top(); strs.pop();

                string temp = "";
                for (int i = 0; i < k; i++) temp += curr;

                curr = prev + temp;
            } 
            else {
                curr += c;
            }
        }
        return curr;
    }
};