class MinStack {
    std::vector<int> v;
    std::map<int, int> m;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        v.push_back(val);
        m[val] += 1;
    }
    
    void pop() {
        int val = v.back();
        v.pop_back();
        m[val] -= 1;
        if (m[val] == 0)
            m.erase(val);
    }
    
    int top() {
        return v.back();
    }
    
    int getMin() {
        return m.begin()->first;
    }
};
