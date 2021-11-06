class Solution {
    
    var currVal: Int = 0
    var dict = Dictionary<Int, Bool>()
    
    func isHappy(_ n: Int) -> Bool {
        var nStrArr = Array(String(n))    
        repeat {
            // update the number 
            currVal = 0            
            for _n in nStrArr {
                let _nInt: Int? = Int(String(_n))
                currVal += _nInt! * _nInt!
            }

            // check the number is cycled 
            if dict.keys.contains(currVal) {
                return false
            } else {
                dict[currVal] = true
            }
            
            // reset
            nStrArr = Array(String(currVal))            
        } while( currVal != 1 )
        
        return true  
    }
}
