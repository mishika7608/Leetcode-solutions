class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (int i=0;i<asteroids.size();i++){
            if (asteroids[i]>0){
                ans.push_back(asteroids[i]);
            }
            else{
                while(!ans.empty() && ans[ans.size()-1] > 0 && ans[ans.size()-1]<abs(asteroids[i])){
                    ans.pop_back();
                }if (!ans.empty() && ans[ans.size()-1] > 0 && ans[ans.size()-1]>abs(asteroids[i])){}
                else if (!ans.empty() && ans[ans.size()-1] > 0 && ans[ans.size()-1]==abs(asteroids[i])){ans.pop_back();}
                else{ans.push_back(asteroids[i]);}
            }
        }
        return ans;
    }
};
