template<typename T>
class MyQueue {
private:
    vector<T> window;
    map<long long, bool> mapper;

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
        auto it = mapper.find((long long)front_num); 
        if (it != mapper.end()) { // if exist, then remove  
            mapper.erase(it);
        } 
    }
    
    void push(T num, const int &thres) {
        // update the window 
        window.emplace_back(num);

        // update the mapper 
        long long numlong {num};
        long long threslong {thres};
        auto is_similar = [&numlong, &threslong](std::pair<T, bool> i){ return std::abs(numlong - i.first) <= threslong; };
        auto it = std::find_if(mapper.begin(), mapper.end(), is_similar); // takes much times? 
        if (it == mapper.end()) {  // if no exist, then append
            mapper.insert({numlong, true});
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
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int thers) 
    {
        for(auto& elm: nums) 
        {    
            if( checker.size() <= k ) {
                checker.push(elm, thers);   
            } else {
                checker.pop();  
                checker.push(elm, thers);   
            }

            if( checker.is_answer_found() ) {
                return true;                 
            } 
        }
        
        return false; 
    }
}; 
