void printVec(const vector<int>& nums) {
    for(const auto& elm: nums) {
        cout << elm << " ";
    }
    cout << endl;
}

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // sort 
        // std::sort(nums.begin(), nums.end());
        // cout << "sorted:" << endl;
        // printVec(nums);
        
        // index-frequency table (map)
        unordered_map<int /*num*/, int /*frequency*/> nums_freq;
        for(auto& num: nums) {
            nums_freq[num]++;
        }
        // cout << "nums frequency table is constructed:" << endl;
        // for(auto& num: nums_freq) {
        //     cout << " " << num.first << "/" << num.second << endl;
        // } 
        
        // main: O(n3) alg. 
        set<multiset<int>> answer_ms;
        size_t nums_len = nums.size();
        for(int a=0; a<nums_len; ++a) {
            for(int b=a+1; b<nums_len; ++b) {
                for(int c=b+1; c<nums_len; ++c) {
                    // 3-tuple to be tested 
                    int& na = nums[a];
                    int& nb = nums[b];
                    int& nc = nums[c];
                    // cout << "abc:" << na << " " << nb << " " << nc << endl;

                    // marks used 
                    nums_freq[na]--; 
                    nums_freq[nb]--; 
                    nums_freq[nc]--;  

                    // find the last one or not 
                    int expected_nd = int(long(target) - (long(na) + long(nb) + long(nc)));                    
                    // cout << " expected_nd: " << expected_nd << endl;
                    if (nums_freq[expected_nd] == 0 /* means if the number does not exist 
                        or the existing single number is already used */) {
                        // cout << " No possible 4 tuple" << endl;                        
                    } else {
                        // cout << " The possible 4-tuple is: " 
                        //      << na << " " << nb << " " << nc << " " << expected_nd << endl;

                        // save the multi-set to vector
                        answer_ms.insert({na, nb, nc, expected_nd});
                    }

                    // reset unused
                    nums_freq[na]++;  
                    nums_freq[nb]++; 
                    nums_freq[nc]++; 
                }            
            }            
        }
        
        // verification and transform the set<multiset> to the return format 
        vector<vector<int>> answer;
        for(auto& ms: answer_ms) {
            vector<int> tuple4;
            for(auto& elm: ms) {
                // cout << elm << " ";
                tuple4.emplace_back(elm);
            }
            // cout << endl;
            answer.emplace_back(tuple4);
        }
        
        return answer;
    }
};
