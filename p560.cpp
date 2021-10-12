// NOTE
// - following the implementation of the solution Approach 4 (O(n) method using subarray's precalculated results stored using map) 

/* result
    Runtime: 84 ms, faster than 60.52% of C++ online submissions for Subarray Sum Equals K.
    Memory Usage: 36.2 MB, less than 50.82% of C++ online submissions for Subarray Sum Equals K.
*/

bool isMapContainsTheElm(const unordered_map<int, int>& _map, int elm) {
    return _map.find(elm) != _map.end();
}

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // vars 
        int counts = 0; 
        unordered_map<int, int> accumulated_sums_map;
        
        // init
        int currrent_accumulated_sum = 0;
        accumulated_sums_map[currrent_accumulated_sum]++; 
        // main  
        for(auto& num: nums) {
            currrent_accumulated_sum += num;

            int k_subtracted_sum = currrent_accumulated_sum - k;
            // if( isMapContainsTheElm(accumulated_sums_map, k_subtracted_sum) ) { // 145 ms	
            if( accumulated_sums_map.find(k_subtracted_sum) != accumulated_sums_map.end() ) { // 64 ms	
                counts += accumulated_sums_map[k_subtracted_sum];
            } 
            
            accumulated_sums_map[currrent_accumulated_sum]++; 
        }
        
        return counts; 
    }
};
