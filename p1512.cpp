
class Solution 
{
    int count_;        
    
public:
    int numIdenticalPairs(vector<int>& nums) 
    {
        auto len = nums.size();
        for (int ii=0; ii<len; ii++) 
        {   
            for (int jj=0; jj<len; jj++) 
            {
                if(jj <= ii)
                    continue;
                
                if(nums.at(ii) == nums.at(jj))
                    count_++;   
            }
        }
        
        return count_;
    }
};
