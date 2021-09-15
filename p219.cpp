/*
  Runtime: 976 ms, faster than 5.02% of C++ online submissions for Contains Duplicate II.
  Memory Usage: 81 MB, less than 10.54% of C++ online submissions for Contains Duplicate II.
*/

template<typename T>
class MyQueue {
private:
    vector<T> window;
    map<T, bool> mapper;

    bool answer_found = false; 
        
public: 
    void pop(void) {
        T front_num = window.at(0);

        // update the window 
        if( !window.empty() ) {
            window.erase(window.begin());        
        } else {
            cout << "[WARN] no pop, window is empty!" << endl;
        }

        // update the mapper  
        auto it = mapper.find(front_num); 
        if (it != mapper.end()) { // if exist, then remove  
            mapper.erase(it);
        } 
    }
    
    void push(T num) {
        // update the window 
        window.emplace_back(num);

        // update the mapper 
        auto it = mapper.find(num); 
        if (it == mapper.end()) {  // if no exist, then append
            mapper.insert({num, true});
        } else { // if double-found, the problem is solved (and return)
            answer_found = true; 
        }
    }

    int size(void) {
        return window.size();
    }

    bool is_answer_found(void) {
        return answer_found;
    }
        
    void print(bool verbose) {
        if(!verbose) {
            return;
        }
        
        for(auto& elm: window) {
            cout << " " << elm;  
        }
        cout << endl; 
    }
};


class Solution {

private:
    MyQueue<int> checker; 

public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        for(auto& elm: nums) 
        {    
            if( checker.size() <= k ) {
                checker.push(elm);   
            } else {
                checker.pop();  
                checker.push(elm);   
            }

            if( checker.is_answer_found() ) {
                return true;                 
            } 
        }
        
        return false; 
    }
}; 


