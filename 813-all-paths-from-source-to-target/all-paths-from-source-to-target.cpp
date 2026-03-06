class Solution {
public:
    void helper(vector<vector<int>> &res,vector<int> &temp,int target, int i,vector<vector<int>> &graph){
        if (i==target){res.push_back(temp);return;}
        for (auto u : graph[i]){
            temp.push_back(u);
            helper(res,temp,target,u,graph);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int target = graph.size()-1;
        vector<vector<int>> res;
        vector<int> temp={0};
        helper(res,temp,target,0,graph);
        return res;
    }
};