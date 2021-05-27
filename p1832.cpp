#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>

class Solution 
{

    const int kNumAlphabets {26};
    // std::map<std::string, int> alphabet_counter; // result 8ms
    std::unordered_map<std::string, int> alphabet_counter; // result 4ms
        
public:
    bool checkIfPangram(string _sentence) 
    {
        for (int ii = 0; ii < _sentence.size(); ii++)
            alphabet_counter[string(1, _sentence[ii])]++;

        if( alphabet_counter.size() >= kNumAlphabets)
            return true;  
        else 
            return false;
    }

};
