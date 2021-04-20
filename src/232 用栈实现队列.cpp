
// 232. Implement Queue using Stacks

class MyQueue {
    stack<int> que, tmp;
    int front;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (que.empty()) {
            front = x;
        }
        
        que.push(x);
        return;
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (que.empty()) {
            return INT_MIN;
        }

        transfer(que, tmp);
        int ret = tmp.top();
        tmp.pop();
        
        if (!tmp.empty()) {
            front = tmp.top();
        }
        
        transfer(tmp,que);
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        if (!que.empty()) {
            return front;
        }
        
        // throw error
        return que.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return que.empty();
    }
    
    void transfer(stack<int>& orc, stack<int>& des) {
        // assert(des.empty());
        while (!orc.empty()) {
            int tmp = orc.top();
            orc.pop();
            des.push(tmp);
        }
        
        return;
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
