#include <map>

class Solution {

    const int MAX_N = 38;
    const int NOT_INITED = -1;
    map<int, int> fibCached;

public:
    Solution() {
        for(int ii=0; ii<MAX_N; ii++) {
            fibCached[ii] = NOT_INITED;
        }
        fibCached[0] = 0;
        fibCached[1] = 1;
        fibCached[2] = 1;
    }

public:
    int tribonacci(int n) {        
        if (fibCached[n] != NOT_INITED) 
            return fibCached[n];
        
        int val = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
        fibCached[n] = val;
        return val;
    }
};
