/**
 * @param {number} n - a positive integer
 * @return {number} - a positive integer
 */

var reverseBits = function(n) {
    
    const N_LEN = 32;  
    n = parseInt(n);
    let ii = 0;
    let reversed_binary_str = '';
    while (ii < N_LEN) {
        let binary_digit_ii = n % 2;
        n = parseInt(n / 2);
        reversed_binary_str += binary_digit_ii;
        ii++;
    }    
    return parseInt(reversed_binary_str, 2);
};
