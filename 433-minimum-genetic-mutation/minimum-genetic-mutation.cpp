#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> geneBank(bank.begin(), bank.end());
        if(!geneBank.count(end)) return -1;

        queue<pair<string,int>> q;
        q.push({start, 0});

        char genes[4] = {'A','C','G','T'};

        while(!q.empty()){
            auto [cur, steps] = q.front();
            q.pop();

            if(cur == end) return steps;

            for(int i=0;i<cur.size();i++){
                char original = cur[i];
                for(char g : genes){
                    if(g == original) continue;
                    cur[i] = g;
                    if(geneBank.count(cur)){
                        q.push({cur, steps+1});
                        geneBank.erase(cur);
                    }
                }
                cur[i] = original;
            }
        }
        return -1;
    }
};