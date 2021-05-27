/*
  - NOTE: runnable only in the leetcode platform 
*/

#include <queue>
#include <deque>

class Solution 
{
    std::deque<int> quu;
    int currTwoSum;
    int currThreeSum;

public:
    int threeSumClosest(vector<int>& nums, int target) 
    {        
        std::vector<int> threeSums;
        currThreeSum = 0;
        for(int ii=0; ii<nums.size(); ii++)
        {
            quu.clear();
            currTwoSum = 0;
            int new_target = target - nums[ii];
            for(int jj=0; jj<nums.size(); jj++)
            {
                int curr_val = nums[jj];
                if(jj == ii)
                    continue;
                
                if(quu.size() < 2) {
                    quu.push_back(curr_val);
                    currTwoSum = currTwoSum + curr_val;
                    continue;
                }
                
                int currDiff = std::abs(currTwoSum - new_target);
                int newTwoSum1 = (quu.front() + curr_val);
                int newTwoSum2 = (quu.back() + curr_val);
                int newDiff1 = std::abs(newTwoSum1 - new_target);
                int newDiff2 = std::abs(newTwoSum2 - new_target);
                
                if( (newDiff1 <= newDiff2) && (newDiff1 <= currDiff) ) {
                    currDiff = newDiff1;
                    currTwoSum = newTwoSum1;
                    quu.pop_back();
                    quu.push_back(curr_val);
                }
                if( (newDiff2 < newDiff1) && (newDiff2 <= currDiff) ) {
                    currDiff = newDiff2;
                    currTwoSum = newTwoSum2;
                    quu.pop_front();
                    quu.push_back(curr_val);
                }                       
            }

            currThreeSum = nums[ii] + currTwoSum;
            threeSums.push_back(currThreeSum);
        }
        
        int nearestThreeSum = 0; 
        int nearestThreeSumDiff = 100000; 
        for(auto& _elm: threeSums)
        {
            if( std::abs(_elm - target) < nearestThreeSumDiff) {
                nearestThreeSumDiff = std::abs(_elm - target);
                nearestThreeSum = _elm;
            }
        }

        return nearestThreeSum;
    }
};
