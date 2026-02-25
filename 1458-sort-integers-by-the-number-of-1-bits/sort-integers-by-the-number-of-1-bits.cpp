class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> temp;
        int n = arr.size();
        for (int i=0;i<n;i++){
            int num = __builtin_popcount(arr[i]);
            temp.push_back({num,arr[i]});
        }
        sort(temp.begin(), temp.end(), [](auto &a, auto &b){
            if (a.first==b.first){
                return a.second<b.second;
            }
            return a.first<b.first;
        });
        for (int i=0;i<n;i++){
            arr[i] = temp[i].second;
        }return arr;
    }
};