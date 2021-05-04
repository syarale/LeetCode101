
// 225. Implement Stack using Queues

class MyStack {
private:
    queue<int> stk, tmp; 
    
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        while (!stk.empty()) {
            tmp.push(stk.front());
            stk.pop();
        }
        
        stk.push(x);
        
        while (!tmp.empty()) {
            stk.push(tmp.front());
            tmp.pop();
        }
        
        return;

    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (!stk.empty()) {
            int topVal = stk.front();
            stk.pop();
            return topVal;
        }
        
        // throw error
        return INT_MIN;
    }
    
    /** Get the top element. */
    int top() {
        if (!stk.empty()) {
            return stk.front();
        }
        
        // throw error
        return INT_MIN;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return stk.empty(); 
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
