#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> queueIn;
    stack<int> queueOut;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if (!queueOut.empty()){
            while (!queueOut.empty()){
                queueIn.push(queueOut.top());
                queueOut.pop();
            }
        }
        queueIn.push(x);
    }
    
    int pop() {
        if (!queueIn.empty()){
            while (!queueIn.empty()){
                queueOut.push(queueIn.top());
                queueIn.pop();
            }
        }
        int x = queueOut.top();
        queueOut.pop(); 
        return x;
    }
    
    int peek() {
        if (!queueIn.empty()){
            while (!queueIn.empty()){
                queueOut.push(queueIn.top());
                queueIn.pop();
            }
        }
        return queueOut.top(); 
    }
    
    bool empty() {
        if (queueIn.empty() && queueOut.empty()) return true;
        else return false; 
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */