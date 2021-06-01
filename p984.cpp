class Solution {
public:
    string strWithout3a3b(int a, int b) {
     
        string answer {""}; 
        
        int maxnum, minnum;
        string xxy, xy, xx, x;
        if( a >= b ) {
            maxnum = a;
            minnum = b;
            xxy = "aab";
            xy = "ab";
            xx = "aa";
            x = "a";
        } else {
            maxnum = b;
            minnum = a;
            xxy = "bba";
            xy = "ba";            
            xx = "bb";
            x = "b";
        }
        
        int num_xxy = min(maxnum - minnum, minnum);
        int num_xy = minnum - num_xxy;
        int num_xx = (num_xy==0 && maxnum%2==0) ? 1 : 0;
        int num_x = (num_xy==0 && maxnum%2==1) ? 1 : 0;

        if(maxnum == 2*minnum) {
            num_xx = 0; 
            num_x = 0;
        }
        
        for(int ii=0; ii<num_xxy; ii++)
            answer = answer + xxy; std::cout << answer << std::endl;
        for(int ii=0; ii<num_xy; ii++)
            answer = answer + xy;  std::cout << answer << std::endl;
        for(int ii=0; ii<num_xx; ii++)
            answer = answer + xx;  std::cout << answer << std::endl;
        for(int ii=0; ii<num_x; ii++)
            answer = answer + x;  std::cout << answer << std::endl;

        
        return answer;
    }
};
