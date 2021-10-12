/* result
    Runtime: 4 ms, faster than 76.26% of C++ online submissions for Find the Middle Index in Array.
    Memory Usage: 12.5 MB, less than 39.07% of C++ online submissions for Find the Middle Index in Array.
*/

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {

        int middle_index = -1;
        
        // O(n): get cummulated sums 
        vector<int> sums {0};
        for(auto& num: nums) {
            sums.push_back(sums[sums.size()-1] + num);
        }
        sums.erase(sums.begin());
        
        // O(n): traverse onces brute force 
        for( int ii=0; ii<sums.size(); ++ii) {
            
            int left_sum = 0;
            if(ii != 0) {
                left_sum = sums[ii-1];
            }
            
            int right_sum = 0;
            if(ii != sums.size()-1) {
                right_sum = sums[sums.size()-1] - sums[ii];
            }
            
            if(left_sum == right_sum) {
                return ii;
            } 
        }
                
        return middle_index;
    }
};
