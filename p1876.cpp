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
