/* Version 
  2021-05-29 slow ver (time exceeded)
*/

/* Explanation 
    given value   : [2,3,0,1,4], and its corresponding indexes are
    location index: [1,2,3,4,5]
    
    then the node 1 element can be connected to the node 2 and 3 
    because node 1 value is 2.

    by repeating this process,     
    now the problem is equal to the Dijkstra's algorithm (shortest path problem)
    1-2--4
    | | \ㅣ
    ㄴ-3  5 
    
    in this graph, the shorted path length is 2 (1-2 then 2-5).

    Steps:
    - 1. constructing a graph from a given array.
    - 2. applying Dijkstra's algorithm.
*/

const int BIGVALUE = 10000000;
const int JUMP_ONCE = 1;

class Solution {

    // vector<int> nums_;
    map<int, vector<pair<int,int>>> edges_; 
    // vector<int> distances_; // from the start node to ith 

public: 
    void makeGraph(vector<int>& nums_)
    {
        for(int idx=0; idx<nums_.size(); idx++) {
            // edges
            for(int jump=0; jump <= nums_[idx]; jump++) {
                if(jump == 0) 
                    continue;
                if(idx+jump >= nums_.size())
                    break;
                edges_[idx].push_back({idx, idx+jump});
            }
        }   
    }
    
public:
    int jump(vector<int>& nums_) 
    {    
        // step 1. constructing a graph from a given array.
        // nums_ = nums;
        makeGraph(nums_);
        
        // step 2. applying Dijkstra's algorithm.
        // init distance with big value 
        vector<int> distances_(nums_.size(), BIGVALUE);

        const int init_idx = 0;
        distances_[init_idx] = 0; // init jump is 0 
        int last_idx = nums_.size() - 1; 

        int curr_idx = init_idx;
        queue<int> quu;    
        quu.push(curr_idx);
    
        set<int> visited_idxes;        
        while( !quu.empty() )
        {
            // try 
            curr_idx = quu.front();
            quu.pop();
                
            // termination condition 
            if( curr_idx == last_idx )
                break;
            
            // main
            if( visited_idxes.find(curr_idx) == visited_idxes.end() )
            {
                auto adjacent_idxes = edges_[curr_idx];
                for(auto& elm: adjacent_idxes) {                    
                    int neighbor_idx = elm.second;
                    int new_dist = distances_[curr_idx] + JUMP_ONCE;
                    if( new_dist < distances_[neighbor_idx]) {
                        distances_[neighbor_idx] = new_dist;
                        quu.push(elm.second);
                    }
                }
                visited_idxes.insert(curr_idx);
            }
        }

        return distances_[last_idx];
    }
};

