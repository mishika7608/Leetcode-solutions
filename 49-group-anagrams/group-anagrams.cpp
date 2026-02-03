class Solution {
public:
    void mapfreq(vector<int> &hash,string str){
        for (int i=0;i<str.size();i++){
            hash[str[i]-'a']++;
        }
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> mp;
        int n = strs.size();
        for (int i=0;i<n;i++){
            vector<int> hash(26,0);
            mapfreq(hash,strs[i]);
            mp[hash].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (auto &v: mp){
            ans.push_back(v.second);
        }return ans;
    }
};