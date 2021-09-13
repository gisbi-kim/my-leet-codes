/*
Note:
    - This implementation is O(n) that search for all grids once. 
    - The std::endl below (was used for the debugging-driven development) required heavy time consumption so comment them for the submission time. 

Result:    
    Runtime: 108 ms, faster than 36.23% of C++ online submissions for Island Perimeter.
    Memory Usage: 96.3 MB, less than 58.25% of C++ online submissions for Island Perimeter.
*/

#include <utility>

using std::cout;
using std::endl;
using std::size_t;
    
bool isCellLand(int cell_type) {
    if(cell_type == 0)
        return false;
    else 
        return true;
}

bool isThisCellOutOfMap(const std::pair<int, int>& loc, const std::pair<int, int>& map_shape) {
    
    int min_x = 0;
    int min_y = 0;
    const int& max_x = map_shape.first;
    const int& max_y = map_shape.second;
    
    const int& x = loc.first;
    const int& y = loc.second;
    // cout << "  neighbor location: " << x << ", " << y << endl;
    if ( x < min_x || max_x <= x ||
         y < min_y || max_y <= y ) {
        // cout << "    out of the map!" << endl;
        return true;
    }
    return false;     
}

int countAdjLandCells(const std::pair<int, int>& loc, const vector<vector<int>>& grid) {
    std::size_t num_row = grid.size();
    std::size_t num_col = grid.at(0).size();
    std::pair<int, int> map_shape {num_row, num_col};

    const int& x = loc.first;
    const int& y = loc.second;
    
    int counts = 4; 
    std::array<int, 4> adj_x {x-1, x+1, x, x}; // left, right, up, down 
    std::array<int, 4> adj_y {y, y, y+1, y-1}; // left, right, up, down 
    
    // boundary check 
    for (int ii=0; ii<4; ++ii) {
        if( isThisCellOutOfMap({adj_x[ii], adj_y[ii]}, map_shape) ) {
            counts--;
        } else {
            if( ! isCellLand(grid[adj_x[ii]][adj_y[ii]])) {
                counts--;
            }
        }
    }
            
    return counts;
}

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        std::size_t num_row = grid.size();
        std::size_t num_col = grid.at(0).size();
        std::pair<int, int> map_shape {num_row, num_col};
        // cout << num_row << ", " << num_col << endl;

        int sum_perimeters {0};
        for(size_t ii_row=0; ii_row < num_row; ++ii_row ) 
        {
            for(size_t ii_col=0; ii_col < num_col; ++ii_col ) {
                auto cell_type = grid[ii_row][ii_col];
                std::pair<int, int> curr_location {ii_row, ii_col};
                if( isCellLand(cell_type) ) {
                    int num_adj_lands = countAdjLandCells(curr_location, grid);
                    // cout << "The land cell [" << ii_row << ", " << ii_col << "] has " 
                         // << num_adj_lands << " adjacent land cells." << endl;
                    
                    int this_perimeter = 4 - num_adj_lands;
                    sum_perimeters += this_perimeter;
                }
            }
        }
        
        return sum_perimeters;
    }
};
