class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> mpq;

        for (int s : stones)
            mpq.push(s);

        
        while (mpq.size() > 1) {
            // stupid condition, will never happen.............
            //if (mpq.size() == 0)
            //    return 0;

            int y = mpq.top();
            mpq.pop();
            int x = mpq.top();
            mpq.pop();

            //std::cout << x << " " << y << " size: " << mpq.size() << "\n";

            if (x == y) {
                continue;
            } else if (x < y) {
                y = y - x;
                mpq.push(y);
                //std::cout << "replaced with: " << y << "size: " << mpq.size() << "\n";
            }
        }

        mpq.push(0);
        return mpq.top();
    }
};
