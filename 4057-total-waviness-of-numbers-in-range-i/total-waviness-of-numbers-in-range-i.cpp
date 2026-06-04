class Solution {
public:
    int calcWave(int n){
        if (n<100){
            return 0;
        }
        int wave=0;
        int a=n%10;n/=10;
        int b=n%10;n/=10;
        int c=n%10;n/=10;
        if (a<b && b>c){wave+=1;}
        if (a>b && b<c){wave+=1;}
        while (n>0){            
            a=b;
            b=c;
            c=n%10;n/=10;
            if (a<b && b>c){wave+=1;}
            if (a>b && b<c){wave+=1;}
        }
        return wave;
    }
    int totalWaviness(int num1, int num2) {
        int total=0;
        for (int i=num1;i<=num2;i++){
            total+=calcWave(i);
        }
        return total;
    }
};