class Solution {
public:
    int funcGCD(int a, int b){
        if (b==0 || a==0){return 0;}
        while (b!=0){
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }
    bool canMeasureWater(int x, int y, int target) {
        if (target>x+y){
            return false;
        }
        else if (target==x+y){
            return true;
        }
        return target%funcGCD(x,y)==0;
    }
};
