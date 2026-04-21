class KthLargest {
    std::priority_queue<int> mpq;
    int k;
public:
    KthLargest(int k, vector<int>& nums): k(k) {
        for (int n : nums)
            mpq.push(n);
    }
    
    int add(int val) {
        mpq.push(val);
        size_t qsize = mpq.size();

        std::vector<int> tmp;

        for (int i = 0; i < k; i++) {
            tmp.push_back(mpq.top());
            mpq.pop();
        }
        
        int res = tmp.back();

        for (int i : tmp)
            mpq.push(i);

        return res;
    }
};
