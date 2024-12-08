class MinStack {
private:
        vector<int> stack;
        vector<int> min_stack;
public:
    MinStack() {
        stack = {};
        min_stack = {};
    }
    
    void push(int val) {
        if (stack.empty())
            min_stack.push_back(val);
        else {
            if (val <= min_stack.back())
                min_stack.push_back(val);
        }
        stack.push_back(val);

    }
    
    void pop() {
        if (min_stack.back() == stack.back())
            min_stack.pop_back();

        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return min_stack.back();
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