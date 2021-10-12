/* idea: double two-pointer strategy 

# implementation
1/ 
first consruct index / consecutive_counts table 
ex. input is [3,3,3,1,1,2,1,1,2,2,3,3,3,3,5],
    idx: 3 1 2 1 2 3 5
    #  : 2 2 1 2 2 4 1 

the data structure we use is vector<pair<fruit, count>>

2/ 
traverse the idx row with two-pointer strategy 

*/
    

/* result
    Runtime: 216 ms, faster than 21.68% of C++ online submissions for Fruit Into Baskets.
    Memory Usage: 63.8 MB, less than 22.90% of C++ online submissions for Fruit Into Baskets.
*/

vector<pair<int, int>> consructFruitTable(vector<int>& fruits) {
    vector<pair<int /*fruit*/, int /*count*/>> fruit_table;
    int prev_fruit = fruits.at(0);
    int curr_fruit = fruits.at(0);
    int curr_fruit_consecutive_counts = 0;
    // bool is_first_fruit = true;

    for(auto& fruit: fruits) {  
        //
        curr_fruit = fruit;

        // 
        if( curr_fruit == prev_fruit ) {
            curr_fruit_consecutive_counts++;
        } else {
            fruit_table.push_back({prev_fruit, curr_fruit_consecutive_counts});
            curr_fruit_consecutive_counts = 1;
        }

        //
        prev_fruit = curr_fruit;
    }
    
    // append the last 
    fruit_table.push_back({prev_fruit, curr_fruit_consecutive_counts});
    
    return fruit_table;
}


bool isNewFruit(int fruit, const vector<int>& picked_fruit_types) {
    for(auto& picked_fruit: picked_fruit_types) {
        // cout << " picked_fruit is " << picked_fruit << endl; 
        if( fruit == picked_fruit ) {
            return false;
        }
    }
    return true; 
}

int traverseFruitTable(const vector<pair<int, int>>& fruit_table) {
    const int num_baskets = 2;

    int start_pointer = 0; 
    int end_pointer = -1;
    
    int max_counts = 0;
    int curr_total_counts = 0;
    vector<int> picked_fruit_types;
    for(auto& elm: fruit_table) {
        //
        int fruit_type = elm.first;
        int fruit_count = elm.second;
        // cout << "fruit: " << fruit_type << endl;
        // condition 1 
        if( picked_fruit_types.size() < num_baskets ) {
            // update fruit types 
            picked_fruit_types.push_back(fruit_type);
            
            // update pointers 
            end_pointer++;
            
            // update the summed counts 
            curr_total_counts += fruit_count;
        } 
        // condition 2 
        else if( isNewFruit(fruit_type, picked_fruit_types) ) {
            // cout << "is new fruit" << endl;
            // update fruit types 
            picked_fruit_types.erase(picked_fruit_types.begin());
            picked_fruit_types.push_back(fruit_type);
            
            // update pointers             
            start_pointer = end_pointer;
            end_pointer++;

            // update the summed counts (re-initialized)
            curr_total_counts = fruit_table.at(start_pointer).second + fruit_count; // start count + curr count 
        } 
        else {
            // update fruit types 
            picked_fruit_types.erase(picked_fruit_types.begin());
            picked_fruit_types.push_back(fruit_type);
            
            // update pointers   
            end_pointer++;

            // update the summed counts (re-initialized)
            curr_total_counts += fruit_count;
        }
        
        // cout << curr_total_counts << endl;
        
        //
        if( max_counts <= curr_total_counts) {
            max_counts = curr_total_counts;
        }        
    }

    return max_counts;
}


class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {    
        auto fruit_table = consructFruitTable(fruits);
        // for(auto& elm: fruit_table) { // verification 
        //     cout << elm.first << "/" << elm.second << endl;
        // }
                
        return traverseFruitTable(fruit_table);
    }
};
