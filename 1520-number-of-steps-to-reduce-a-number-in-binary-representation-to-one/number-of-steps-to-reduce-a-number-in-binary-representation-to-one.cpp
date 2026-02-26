class Solution {
public:
    string add(string s){
        int carry=1;
        int n=s.size();
        for (int i=n-1;i>=0;i--){
            if (carry==0){break;}
            if (s[i]=='1'){s[i]='0';}
            else if(s[i]=='0'){s[i]='1';carry=0;}
        }if (carry==1)
        {string t="1";t+=s;return t;}
        return s;
    }
    int numSteps(string s) {
        int steps=0;

        while (s!="1"){
            int n=s.size();
            if (s[n-1]=='1'){
                s=add(s);
            }else{
                s=s.substr(0,n-1);
            }
            steps++;
        }return steps;
    }



    // WORKS FOR SMALLER LENGTH
    // long long findNum(string s){
    //     int n = s.size();
    //     long long num=0;long long j=1;
    //     for (int i=n-1;i>=0;i--,j*=2){
    //         if (s[i]=='1'){
    //             num+=j;
    //         }
    //     }return num;
    // }
    // int numSteps(string s) {
    //     long long num = findNum(s);
    //     int step=0;
    //     while (num!=1){
    //         if(num%2==0){
    //             num/=2;
    //         }else{num+=1;}
    //         step++;
    //     }return step;
    // }

};