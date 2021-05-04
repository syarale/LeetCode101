
// 155. Min Stack

class MinStack {

stack<int> stk, minStk;
    
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int val) {
        stk.push(val);
        
        if (minStk.empty()) {
            minStk.push(val);
            return;
        }
        
        
        int minVal = minStk.top();
        if (val < minVal) {
           minStk.push(val);
        } else {
           minStk.push(minVal);
        } 
        
        return;

    }
    
    
    void pop() { 
        if (!stk.empty()) {
            stk.pop();
            minStk.pop();
            return;
        }

        // throw error
        return;
    }
    
    int top() {
        if (!stk.empty()) {
            return stk.top();
        }

        // throw error
        return INT_MIN;
    }
    
    int getMin() {
        if (!minStk.empty()) {
            return minStk.top();
        }

        // throw error
        return INT_MIN;
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
