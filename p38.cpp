using std::cout;
using std::endl;

class RepeatCount {
public:
    RepeatCount(char _digit, int _count)
    : digit(_digit), count(_count) { }
public:
    char digit;
    int count; 
};

std::vector<RepeatCount> splitAdjacentRepeatedBlocks(const string& num) {
    // assume that the num has minimum length of 1 (i.e., not empty)
    std::vector<RepeatCount> result;
    char prev_digit {'#'}; // # means uninitialized.
    for(const auto& _n: num) {
        if (_n == prev_digit) { 
            result.back().count++;
        } else {
            result.emplace_back(RepeatCount(_n, 1));
        }
        prev_digit = _n;
    }
    return result;
}

string concatVecRepeatCount(std::vector<RepeatCount> digit_counts) {
    string result {""};
    for(const auto& _dc: digit_counts) {
        result += std::to_string(_dc.count); 
        result += _dc.digit; 
    }
    return result;
}

class Solution {
public:
    string countAndSay(int n) {       
        if (n == 1) {
            return "1";
        } else {
            auto digit_counts = splitAdjacentRepeatedBlocks(countAndSay(n-1));
            return concatVecRepeatCount(digit_counts);                
        }
    }
};
