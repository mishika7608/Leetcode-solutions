#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        for(auto &row : board)
            for(int c : row) start += to_string(c);
        
        string target = "123450";

        vector<vector<int>> neighbors = {
            {1,3},      // 0 can swap with 1,3
            {0,2,4},    // 1
            {1,5},      // 2
            {0,4},      // 3
            {1,3,5},    // 4
            {2,4}       // 5
        };

        queue<pair<string,int>> q;
        unordered_set<string> visited;

        q.push({start,0});
        visited.insert(start);

        while(!q.empty()){
            auto [state, moves] = q.front();
            q.pop();

            if(state == target) return moves;

            int zeroPos = state.find('0');
            for(int n : neighbors[zeroPos]){
                string next = state;
                swap(next[zeroPos], next[n]);
                if(!visited.count(next)){
                    visited.insert(next);
                    q.push({next, moves+1});
                }
            }
        }
        return -1;
    }
};