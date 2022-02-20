/**
 * @param {number[]} nums
 * @return {number}
*/

/**
  Runtime: 67 ms, faster than 85.24% of JavaScript online submissions for House Robber.
  Memory Usage: 42.6 MB, less than 6.39% of JavaScript online submissions for House Robber.
*/

let money_robbed_memo;
let house_money_list;

let dfs = function(start_house_idx) {
    if( start_house_idx >= house_money_list.length ) {
        console.log('return 0');
        return 0;
    }    
    if( money_robbed_memo[start_house_idx] != -1 ) {
        return money_robbed_memo[start_house_idx]
    }
    
    let robbed_money_total_possible_case1 = house_money_list[start_house_idx] + dfs(start_house_idx+2);
    let robbed_money_total_possible_case2 = dfs(start_house_idx+1);
    
    money_robbed_memo[start_house_idx] = Math.max(robbed_money_total_possible_case1, robbed_money_total_possible_case2);
    
    return money_robbed_memo[start_house_idx];
}

var rob = function(nums) {

    house_money_list = nums;

    let money_robbed_memo_init = Array(nums.length).fill(-1);
    money_robbed_memo = money_robbed_memo_init;
        
    return dfs(0);
};
