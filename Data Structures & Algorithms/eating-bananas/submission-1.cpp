class Solution {
   public:
    int canEat(vector<int>& piles, int h) {
        int l = 1;
        int r = *std::max_element(piles.begin(), piles.end());

        int res = r;

        while (l <= r) {
            int mid = (r - l) / 2 + l;

            long long totalTime = 0;

            for (int p : piles) {
                totalTime += std::ceil(static_cast<double>(p) / mid);
            }

            if (totalTime <= h) {
                res = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return res;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        return canEat(piles, h);
    }
};
