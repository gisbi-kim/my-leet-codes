/*
    Runtime: 456 ms, faster than 19.96% of C++ online submissions for 3Sum.
    Memory Usage: 24.7 MB, less than 25.47% of C++ online submissions for 3Sum.
*/

#include <set>
// #include <chrono>

// #include <ctime>
// #include <cstdlib>
// #include <chrono>

// class TicToc
// {
// public:
//     TicToc()
//     {
//         tic();
//     }

//     TicToc( bool _disp )
//     {
//         disp_ = _disp;
//         tic();
//     }

//     void tic()
//     {
//         start = std::chrono::system_clock::now();
//     }

//     void toc(string prescript = " ")
//     {
//         end = std::chrono::system_clock::now();
//         std::chrono::duration<double> elapsed_seconds = end - start;
//         double elapsed_ms = elapsed_seconds.count() * 1000;

//         if( disp_ )
//         {
//           std::cout.precision(3); // 10 for sec, 3 for ms 
//           std::cout << prescript << " " << elapsed_ms << " msec." << std::endl;
//         }
//     }

//     std::chrono::time_point<std::chrono::system_clock> start, end;
//     bool disp_ = false;
// };


const int TARGET = 0;

class Solution 
{    
    vector<vector<int>> answer_; 
    set<vector<int>> answer_set_; 
    
    // TicToc tictoc;
        
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {                
        // tictoc.disp_ = true;
        cout << "input size: " << nums.size() << endl;
        if( nums.size() < 3 ) return answer_;
        
        // tictoc.tic();
        sort(nums.begin(), nums.end());
        // tictoc.toc("sort");

        // tictoc.tic();
        // two-pointer appraoch 
        for(int ii=0; ii<nums.size(); ii++) 
        {
            // tictoc.tic();
            int new_target = TARGET - nums[ii];
                           
            vector<int> vec {nums[ii], 0, 0};
                
            auto it_init = nums.begin() + (ii+1);
            auto it_end = nums.end() - 1;

            auto it_left = it_init;
            auto it_right = it_end;
            while ( (it_right - it_left) > 0 )
            {
                auto curr_sum = (*it_left)+(*it_right);
                if( curr_sum == new_target )
                {
                    vec[1] = *it_left; 
                    vec[2] = *it_right;
                    // sort(vec.begin(), vec.end()); // redundant because already sorted (768 ms to 436 ms)
                    answer_set_.insert( vec );
                    
                    if(it_right == it_init)
                        break;
                    it_right--;
                }
                else if( curr_sum < new_target ) {
                    if(it_left == it_end)
                        break;
                    it_left++;                    
                }
                else if( curr_sum > new_target ) {
                    if(it_right == it_init)
                        break;
                    it_right--;
                }
            }
            
            // tictoc.toc("submain");
        } 
        // tictoc.toc("main");

        // for(auto& vec: answer_set_) {
        //     answer_.push_back(vec);
        // }
        // return answer_;
        return std::vector<std::vector<int>>(answer_set_.begin(), answer_set_.end());
    }
};
