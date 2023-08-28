class MyStack {
private:
    queue<int> a;
    queue<int> b; 
    bool add;   //if true a has been added to last
public:
    MyStack() {
        add = false;
    }
    
    void push(int x) {
        if (add)
            b.push(x);
        else
            a.push(x);
        add = !(add);
    }
    
    int pop() {
        if (add){
            int length = a.size();
            for (length; length > 1; length--){
                int temp = a.front();
                a.pop();
                a.push(temp);
            }
            int ans = a.front();
            a.pop();
            add = !(add);
            return ans;
        } else {
            int length = b.size();
            for (length; length > 1; length--){
                int temp = b.front();
                b.pop();
                b.push(temp);
            }
            int ans = b.front();
            b.pop();
            add = !(add);
            return ans;
        }
        return -1;
    }
    
    int top() {
        if (add){
            int length = a.size();
            for (length; length > 1; length--){
                int temp = a.front();
                a.pop();
                a.push(temp);
            }
            int ans = a.front();
            a.pop();
            a.push(ans);
            return ans;
        } else {
            int length = b.size();
            for (length; length > 1; length--){
                int temp = b.front();
                b.pop();
                b.push(temp);
            }
            int ans = b.front();
            b.pop();
            b.push(ans);
            return ans;
        }
    }
    
    bool empty() {
        return (a.empty() && b.empty());
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
