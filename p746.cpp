#include <map>

class Solution {

    const int NOT_INITED = -1;
    map<int, int> costCached;

    vector<int> cost_;

public:
    int minCostClimbingStairs(int n) {
        if(n==0) return cost_[0];
        if(n==1) return cost_[1];
        
        if (costCached[n] != NOT_INITED) 
            return costCached[n];

        int val = min(minCostClimbingStairs(n-1), minCostClimbingStairs(n-2))
                    + cost_[n];
        costCached[n] = val;
        return val;
    }

public:
    int minCostClimbingStairs( vector<int>& cost ) {      
        cost_.push_back(0); // init cost is zero (padding)
        cost_.insert(cost_.end(), cost.begin(), cost.end()) ; // copy 
        cost_.push_back(0); // last cost is zero (padding)

        for(int ii=0; ii<cost_.size(); ii++) {
            costCached[ii] = NOT_INITED;
        }

        return minCostClimbingStairs(cost_.size()-1);
    }
};


