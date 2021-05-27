#include <string>
#include <vector>
#include <iostream>

std::string romI = "I"; // 1
std::string romV = "V"; // 5
std::string romX = "X"; // 10
std::string romL = "L"; // 50
std::string romC = "C"; // 100
std::string romD = "D"; // 500
std::string romM = "M"; // 1000
std::string romM5 = "M5"; // 5000
std::string romM10 = "M10"; // 10000


class Solution {

    std::vector<std::vector<std::string>> table_;

public: 
    void initTable(void)
    {
        // init and reserve space
        for(int ii=0; ii<4; ii++) {
            std::vector<string> vec(10, string{""});
            table_.push_back(vec);
        }

        std::vector<std::string> romBottoms {romI, romX, romC, romM};
        std::vector<std::string> romMids {romV, romL, romD, romM5};
        std::vector<std::string> romUps {romX, romC, romM, romM10};
        for(int ii=0; ii<4; ii++) 
        {
            std::string romBottom = romBottoms[ii];
            std::string romMid = romMids[ii];
            std::string romUp = romUps[ii];
            
            table_[ii][0] = string{""};
            table_[ii][1] = romBottom;
            table_[ii][2] = romBottom + romBottom;
            table_[ii][3] = romBottom + romBottom + romBottom;
            table_[ii][4] = romBottom + romMid;
            table_[ii][5] = romMid;
            table_[ii][6] = romMid + romBottom;
            table_[ii][7] = romMid + romBottom + romBottom;
            table_[ii][8] = romMid + romBottom + romBottom + romBottom;
            table_[ii][9] = romBottom + romUp;
        }
    }

public:
    string intToRoman(int num) 
    {
        initTable();

        std::string romnum {""}; 
        string numstr = std::to_string(num);
        for (int ii = 0; ii < numstr.size(); ii++){
            romnum = romnum + table_[(numstr.size()-1)-ii][ int(std::stoi(string{numstr[ii]})) ];
        }

        return romnum;
    }
};
