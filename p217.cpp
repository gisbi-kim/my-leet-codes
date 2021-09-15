/*
  Runtime: 52 ms, faster than 18.91% of C++ online submissions for Contains Duplicate.
  Memory Usage: 20.8 MB, less than 35.33% of C++ online submissions for Contains Duplicate.
*/

class Solution {
private: 
    map<int, bool> checker; 
    
public:
    
    bool containsDuplicate(vector<int>& nums) 
    {
        for(auto& elm: nums) {
            auto it = checker.find(elm); 
            if (it == checker.end()) { 
                checker.insert({elm, true});
            } else {
                return true; 
            }
        }
        return false; 
    }
};
