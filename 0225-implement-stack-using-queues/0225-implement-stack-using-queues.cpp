class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        int delVal = q1.front();
        q1.pop();
        //swap(q1,q2);
        while(q2.size()>0){
            q1.push(q2.front());
            q2.pop();
        }


        return delVal;
    }
    
    int top() {
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        int top = q1.front();
        q2.push(q1.front());
        q1.pop();

        //swap(q1,q2);
        while(q2.size()>0){
            q1.push(q2.front());
            q2.pop();
        }


        return top;
        
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */