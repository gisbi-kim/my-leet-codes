#include<map>
#include<deque>

using std::cout;
using std::endl; 

std::vector<bool> is_alphabet_used_table; 
std::vector<int> is_alphabet_where_used_table; 
const int NUM_CHARS_MAX = 1000;

std::map<char, int> IdxTableOfAlphabet;

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {    
        // init 
        is_alphabet_used_table = vector<bool>(NUM_CHARS_MAX, false);
        is_alphabet_where_used_table = vector<int>(NUM_CHARS_MAX, -1);

        int cur_count = 0;
        int max_count = 0;
        
        // init existing charactre map 
        int allocated_char_idx = 0;
        for(auto _c : s) {
            if( IdxTableOfAlphabet.find(_c) == IdxTableOfAlphabet.end() ) {
                IdxTableOfAlphabet[_c] = allocated_char_idx;
                allocated_char_idx++;
            }            
        }

        // main 
        int max_size = 0;
        deque<int> substr;
        for(char& _c : s) 
        {
            cout << _c << endl;
            
            int char_idx = IdxTableOfAlphabet[_c];
            cout << "char_idx " << char_idx << endl;

            bool is_char_used = is_alphabet_used_table[char_idx];
            if( ! is_char_used ) {
                substr.push_back(char_idx);                
                is_alphabet_used_table[char_idx] = true;  
                is_alphabet_where_used_table[char_idx] = substr.size();
                cout << "added and substr.size() " << substr.size() << endl; 
            } else {
                for(int ii=0; ii<is_alphabet_where_used_table[char_idx]; ii++) {
                    cout << "is_alphabet_where_used_table[char_idx] " << is_alphabet_where_used_table[char_idx] << endl;
                    cout << "pop front " << substr.front() << endl;
                    is_alphabet_used_table[substr.front()] = false;  
                    substr.pop_front();     
                }
                
                for(auto& _char_idx: substr)
                    is_alphabet_where_used_table[_char_idx] = is_alphabet_where_used_table[_char_idx] - is_alphabet_where_used_table[char_idx];

                substr.push_back(char_idx);                
                is_alphabet_used_table[char_idx] = true;  
                is_alphabet_where_used_table[char_idx] = substr.size();                
            }
            cout << "substr.size() " << substr.size() << endl;
            if(substr.size() > max_size)
                max_size = substr.size();
        }
        // 
        return max_size;
    }
};
