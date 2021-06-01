#include <unordered_map>

class Solution {
    
    std::unordered_map<int, int> table; 
    std::unordered_map<int, bool> table_bool; 
    std::unordered_map<int, vector<int>> table_location_list; 
    
public:
    int findShortestSubArray(vector<int>& nums) {
     
        // init 
        for(auto& _elm: nums) {
            table[_elm] = 0; 
            table_bool[_elm] = true;
        }

        // count frequencies and where they occured 
        int ii = 0;
        for(auto& _elm: nums) {
            table[_elm]++; 
            table_location_list[_elm].push_back(ii);
            ii++;
        }

        // find max 
        int deg = 0;
        for(auto& _elm: table) {
            if(_elm.second >= deg) {
                deg = _elm.second;
            }
        }
        std::cout << "deg is " << deg << std::endl;

        // find argmaxes
        vector<int> deg_digits; 
        for(auto& _elm: table) {
            if(_elm.second == deg) {
                deg_digits.push_back(_elm.first);
                std::cout << "argdeg is " << _elm.first << std::endl;
            }
        }

        // check the subarray len and find minimum 
        int minlen = 10000000;
        for(auto& _elm: deg_digits) {
            int deg_digit_subarray_len = table_location_list[_elm].back() - table_location_list[_elm].front() + 1;
            std::cout << "argdeg has subarray length " << deg_digit_subarray_len << std::endl;
            
            if(minlen > deg_digit_subarray_len)
                minlen = deg_digit_subarray_len;
        }
        
        
        return minlen;
    }
};
