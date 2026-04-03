class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        int units=0;
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int> &a, vector<int> &b)
        {return a[1]>b[1];});
        int i=0;
        while (truckSize && i<n){
            int small = min(truckSize, boxTypes[i][0]);
            units+=(small*boxTypes[i][1]);
            truckSize-=small;
            i++;
        }return units;
    }
};