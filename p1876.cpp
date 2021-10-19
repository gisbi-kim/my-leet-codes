/*
result 
    Runtime: 0 ms, faster than 100.00% of C++ online submissions for Substrings of Size Three with Distinct Characters.
    Memory Usage: 6.1 MB, less than 94.50% of C++ online submissions for Substrings of Size Three with Distinct Characters.
*/
class Solution {
public:
    int countGoodSubstrings(string s) {
        int count = 0;
        for(auto it=s.begin(); it<s.end()-2; ++it) {
            if( *it != *(it+1) 
                && *it != *(it+2) 
                && *(it+1) != *(it+2) ) {
                count++;
            }
        }            
        return count;
    }
};
