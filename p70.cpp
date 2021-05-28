#include <map>

class Solution {

    const int MAX_N = 46;
    const int NOT_INITED = -1;
    map<int, int> climbCached;

public:
    Solution() {
        for(int ii=0; ii<MAX_N; ii++) {
            climbCached[ii] = NOT_INITED;
        }
        climbCached[0] = 0;
        climbCached[1] = 1;
        climbCached[2] = 2; 
    }

public:
    int climbStairs(int n) {        
        if (climbCached[n] != NOT_INITED) 
            return climbCached[n];
        
        int val = climbStairs(n-1) + climbStairs(n-2);
        climbCached[n] = val;
        return val;
    }
};

