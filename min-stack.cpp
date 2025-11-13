class MinStack {
    int t;
    int *st;
public:
    MinStack() {
        st=new int[1000];
        t=-1;
    }
    
    void push(int val) {
        if (t<999){
            t++;
            st[t]=val;
            
        }
        return ;
    }
    
    void pop() {
        if (t>-1){
            int x=st[t];
            t--;
        }
        else{
            return ;
        }
    }
    
    int top() {
        return st[t];
    }
    
    int getMin() {
        int min=INT_MAX;
        for (int i=0;i<=t;i++){
            if (min>st[i]){
                min=st[i];
            }
        }
        return min;
    }

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
