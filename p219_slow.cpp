
void printQueue(queue<int> q)
{
	//printing content of queue 
	while (!q.empty()){
		cout<<" "<<q.front();
		q.pop();
	}
	cout<<endl;
}

vector<int> q2v(queue<int> q) {
    vector<int> v;
    while (!q.empty()){
        v.emplace_back(q.front());
        q.pop();
	}
    return v;    
}

bool containsDuplicate(const vector<int>& nums) 
{
    map<int, bool> checker; 
    for(auto& elm: nums) {
        auto it = checker.find(elm); 
        if (it == checker.end()) { 
            checker.insert({elm, true});
        } else {
            return true; 
        }
    }
    return false; 
}

bool containsDuplicate(queue<int> q) {
    return containsDuplicate(q2v(q));
}


class Solution {

private:
    queue<int> checker; 
    
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        for(auto& elm: nums) 
        {    
            if( checker.size() <= k ) {
                checker.push(elm);   
                // printQueue(checker);
            } else {
                checker.pop();  
                checker.push(elm);   
                // printQueue(checker);
            }
                                    
            if( containsDuplicate(checker) ) {
                return true; 
            }
        }
        
        return false; 
    }
}; 
