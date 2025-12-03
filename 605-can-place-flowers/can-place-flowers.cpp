class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size= flowerbed.size();
        if (size==1){if (flowerbed[0]==0 && n==1){return true;}}
        int i=0;
        while (n>0 && i<size){
            if (i!=size-1 && flowerbed[i]==0 && flowerbed[i+1]==0){
                flowerbed[i]=1;n--;i+=2;}
            else if (i==size-1 && flowerbed[i]==0 && flowerbed[i-1]==0){flowerbed[i]=1;n--;i+=2;}
            else if (i!=size-1 && flowerbed[i]==0  && flowerbed[i+1]==1){i++;}
            else{i+=2;}
        }
        return n==0;
    }
};