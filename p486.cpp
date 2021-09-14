
const int kNotInitialized = -1; 

inline bool isInitialized(int val) {
    return val != kNotInitialized;
}
    
class Solution {
    
private:
    vector<vector<int>> rewards_;
    vector<int> nums_;

private:
    int getReward(std::pair<int, int> _range)
    {
        int idx_i = _range.first;
        int idx_j = _range.second;
            
        // corner cases
        if( idx_i > idx_j ) {
            return 0;
        }
        
        // if cached value is available 
        int reward = rewards_[idx_i][idx_j];
        if( isInitialized(reward) ) {
            return reward;
        } 

        // main 
        // case 1: if the player takes the front one 
        int expected_reward_front = nums_[idx_i] + std::min(
                    getReward({idx_i + 2, idx_j    }), // case 1-1: then, if the other player takes the front one from the remained array 
                    getReward({idx_i + 1, idx_j - 1})  // case 1-2: then, if the other player takes the end one from the remained array 
                    );
        // case 2: if the player take the end one 
        int expected_reward_end = nums_[idx_j] + std::min(
                    getReward({idx_i    , idx_j - 2}), // case 2-1: then, if the other player takes the front one from the remained array 
                    getReward({idx_i + 1, idx_j - 1})  // case 2-2: then, if the other player takes the end one from the remained array 
                    );
        
        reward = std::max(expected_reward_front, expected_reward_end);
        rewards_[idx_i][idx_j] = reward;
        
        return reward;
    }

public:
    bool PredictTheWinner(vector<int>& nums) 
    {
        int len = nums.size();
        if( len <= 2) {
            return true;
        }

        nums_ = nums;
        rewards_ = std::move( vector<vector<int>>(len, vector<int>(len, kNotInitialized)) );  
        
        int maximum_reward = getReward({0, len-1});
        
        int sum {0};
        for(auto& elm: nums) {
            sum += elm;
        }

        int player1_score = maximum_reward;
        int player2_score = sum - maximum_reward;
        cout << "The maximum_reward the player 1 can get is: " << player1_score << endl;
        cout << "The maximum_reward the player 2 can get is: " << player2_score << endl;
             
        return player1_score >= player2_score; 
    }
};
