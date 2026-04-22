class Solution {
public:
    bool rec = true;
    std::map<int, int> waysMemo;
    // recursive implem, too slow
    int aux(int n, int sum) {
        if (sum == n) {
            return 1;
        }

        if (sum > n)
            return 0;

        int a = 0;
        int b = 0;
        
        if (waysMemo.find(sum + 1) == waysMemo.end())
            a = aux(n, sum + 1);
        else
            a = waysMemo[sum + 1];

        if (waysMemo.find(sum + 2) == waysMemo.end()) 
            b = waysMemo[sum + 2];
        else
            b = aux(n, sum + 2);

        waysMemo[sum + 1] = a;
        waysMemo[sum + 2] = b;

        return a + b;
    }

    int climbStairsRec(int n) {
        return aux(n, 0);
    }

    int climbingStairsDP(int n) {

    }

    int climbStairs(int n) {
        if (rec) {
            return climbStairsRec(n);
        }
        return -1;
    }
};
