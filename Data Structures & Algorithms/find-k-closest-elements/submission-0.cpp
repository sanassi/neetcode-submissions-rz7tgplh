class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        std::sort(arr.begin(), arr.end(), [x](int a, int b) {
            return (std::abs(a - x) < std::abs(b - x)) ||
                   ((std::abs(a - x) == std::abs(b - x)) && (a < b));
        });

        arr.erase(arr.begin() + k, arr.end());
        std::sort(arr.begin(), arr.end());

        return arr;
    }
};