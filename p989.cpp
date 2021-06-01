#include <cmath>  

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& numvec, int k) {

        // WRONG: this conversion easily causes bit overflow 
        /*
            long sum = k;
            for(int ii=numvec.size()-1; ii >= 0; ii--) 
                sum = sum + ( numvec.at(ii) * std::pow(10, (numvec.size()-(ii+1))) );              

            vector<int> sumvec;
            for(auto& _c: std::to_string(sum))
                sumvec.push_back(_c - '0');    
        */
        
        /* 
          so the conversion of int to digit vec is recommended 
        */
        vector<int> kvec;
        for(auto& _c: std::to_string(k))
             kvec.push_back(_c - '0');    

        std::reverse(kvec.begin(), kvec.end());      
        std::reverse(numvec.begin(), numvec.end());      

        // pad
        int maxlen = std::max(numvec.size(), kvec.size());
        for(int ii=kvec.size(); ii<maxlen; ii++) 
            kvec.push_back(0);
        for(int ii=numvec.size(); ii<maxlen; ii++) 
            numvec.push_back(0);

        vector<int> sumvec;
        int init_upper = 0;
        for (int ii=0; ii < numvec.size(); ii++) {
            int kii = kvec.at(ii);
            int nii = numvec.at(ii);
            
            int curr_init_upper = init_upper;
            int sumii = kii + nii + curr_init_upper;
                        
            int sumii_lower = sumii; 
            if(sumii > 9) {
                init_upper = 1;
                sumii_lower = sumii - 10;
            } else {
                init_upper = 0;                 
            }
            // std::cout << nii << " + " << kii << " + " << curr_init_upper << " = " << sumii_lower << std::endl;

            sumvec.push_back(sumii_lower);   
        }
        
        if(init_upper == 1) // the last upper digit 
            sumvec.push_back(init_upper);   
        
        std::reverse(sumvec.begin(), sumvec.end());
        return sumvec;
    }
};
