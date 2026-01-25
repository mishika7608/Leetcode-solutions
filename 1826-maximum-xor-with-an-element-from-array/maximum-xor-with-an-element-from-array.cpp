class TrieNode{
    public:
    TrieNode* child[2];
    TrieNode(){
        child[0]=child[1]=NULL;
    }
};
class Solution {
public:
    TrieNode* root= new TrieNode();

    void insert(int num){
        TrieNode *node = root;
        for (int i=31;i>=0;i--){
            int bit = (num>>i) & 1;
            if (!node->child[bit]){
                node->child[bit]=new TrieNode();
            }
            node=node->child[bit];
        }
    }
    
    int getMaxXOR(int num){
        TrieNode* node = root;
        if (root->child[0]==NULL && root->child[1]==NULL){return -1;}
        int ans=0;
        for (int i=31;i>=0;i--){
            int bit = (num>>i) & 1;
            if (node->child[1-bit]){
                ans |= (1<<i);
                node = node->child[1-bit];
            }
            else{
                node= node->child[bit];
            }

        }
        return ans;
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res(queries.size());
        int n =nums.size();
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        sort(nums.begin(),nums.end());
        sort(queries.begin(),queries.end(),
        [](const vector<int> &a, const vector<int> &b){return a[1]<b[1];});

        int j=0;
        for (int i=0;i<queries.size();i++){
            int a= queries[i][0];
            int b= queries[i][1];
            int idx=queries[i][2];
            while(j<n && nums[j]<=b){insert(nums[j]);j++;}
            int c= getMaxXOR(a);
            res[idx]=c;
        }return res;
    }



    //BRUTE FORCE
    // vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    //     vector<int> final;
    //     int n = nums.size();
    //     sort(nums.begin(),nums.end());
    //     for (int j=0;j<queries.size();j++){
    //         int a = queries[j][0];
    //         int b = queries[j][1];
    //         int ans=-1;
    //         for (int i=0; i<n && nums[i]<=b;i++){
    //             int c=nums[i];
    //             int res=a ^ c;
    //             ans=max(ans,res);
    //         }
    //         final.push_back(ans);
    //     }return final;
    // }
};