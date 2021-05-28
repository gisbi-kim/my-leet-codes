/*
  Runtime: 24 ms, faster than 85.37% of C++ online submissions for Median of Two Sorted Arrays.
  Memory Usage: 90 MB, less than 17.82% of C++ online submissions for Median of Two Sorted Arrays.
*/

class Solution {

    double med; 
    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        size_t len1 = nums1.size();
        size_t len2 = nums2.size();
        int total_len = int(len1) + int(len2);
        cout << "total_len " << total_len << endl;
        
        bool isOdd;
        if(total_len % 2 == 0) isOdd = false;
        else isOdd = true;
        
        int med_loc;
        if(isOdd) med_loc = (total_len+1) / 2; 
        else med_loc = total_len / 2; 

        vector<int> nums_all;
        nums_all.insert( nums_all.end(), nums1.begin(), nums1.end() );
        nums_all.insert( nums_all.end(), nums2.begin(), nums2.end() );
    
        sort(nums_all.begin(), nums_all.end()); // is fast to do sort for already sorted arrays?
        
        cout << "med_loc " << med_loc << endl;
        if(isOdd) 
            return nums_all[med_loc-1]; // -1 means cpp starts from 0
        else 
            return (nums_all[med_loc-1] + nums_all[med_loc]) / 2.0;
    }
};
