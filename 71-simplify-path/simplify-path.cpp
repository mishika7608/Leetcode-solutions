class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string temp;

        stringstream ss(path);

        while(getline(ss, temp, '/')){
            if(temp == "" || temp == ".") continue;
            else if(temp == ".."){
                if(!st.empty()) st.pop_back();
            }
            else{
                st.push_back(temp);
            }
        }

        string res = "";
        for(string &dir : st){
            res += "/" + dir;
        }

        return res.empty() ? "/" : res;
    }
};