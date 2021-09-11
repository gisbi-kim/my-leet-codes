#include <algorithm>
#include <vector>
#include <string>

using std::cout;
using std::endl;

struct my_sort_rule
{
    inline bool operator() (const int& n1, const int& n2)
    {
        std::string n1_str = std::to_string(n1);
        std::string n2_str = std::to_string(n2);

        auto composed_num_case1 = n1_str + n2_str;
        auto composed_num_case2 = n2_str + n1_str;

        if(composed_num_case1 >= composed_num_case2) {
            return true;                                  
        } else {
            return false;                          
        }        
    }
};


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        // early return: check if all elms are zero 
        if( std::all_of(nums.begin(), nums.end(), [](int i){return i == 0;}) ) {
            return string{"0"};
        }    
    
        // main 
        std::sort(nums.begin(), nums.end(), my_sort_rule());

        std::stringstream stream; 
        for(auto& elm: nums)
        {
            stream << elm;   
        }

        return stream.str(); 
    }
};

/*
    Result: 
    Runtime: 17 ms, faster than 16.60% of C++ online submissions for Largest Number.
    Memory Usage: 11.2 MB, less than 66.36% of C++ online submissions for Largest Number.
*/


