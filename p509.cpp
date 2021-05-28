#include <map>

class Solution {

    const int MAX_N = 31;
    const int NOT_INITED = -1;
    map<int, int> fibCached;

public:
    Solution() {
        for(int ii=0; ii<MAX_N; ii++) {
            fibCached[ii] = NOT_INITED;
        }
    }

public:
    int fib(int n) {
        if (n < 2) 
            return n;
        
        if (fibCached[n] != NOT_INITED) 
            return fibCached[n];
        
        int val = fib(n-1) + fib(n-2);
        fibCached[n] = val;
        return val;
    }
};
