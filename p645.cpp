/* result 
    Runtime: 116 ms, faster than 7.67% of C++ online submissions for Set Mismatch.
    Memory Usage: 30.9 MB, less than 20.27% of C++ online submissions for Set Mismatch.
*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        int the_duplicated_num = 0;
        // unordered_set<int> numset; // this also works.
        set<int> numset;
        for(auto& num: nums) {
            if(numset.find(num) == numset.end()) {
                numset.insert(num);
            } else {
                the_duplicated_num = num;
            }
        }

        int the_missed_num = 0;        
        for(int ii=0; ii<nums.size(); ++ii) {
            int num = ii + 1; 
            if(numset.find(num) == numset.end()) {
                the_missed_num = num;
            }
        }
        
        return {the_duplicated_num, the_missed_num};
    }
};
