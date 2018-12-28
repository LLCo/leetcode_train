/*

On a 2 dimensional grid with R rows and C columns, we start at (r0, c0) facing east.

Here, the north-west corner of the grid is at the first row and column, and the south-east corner of the grid is at the last row and column.

Now, we walk in a clockwise spiral shape to visit every position in this grid. 

Whenever we would move outside the boundary of the grid, we continue our walk outside the grid (but may return to the grid boundary later.) 

Eventually, we reach all R * C spaces of the grid.

Return a list of coordinates representing the positions of the grid in the order they were visited.

 

Example 1:

Input: R = 1, C = 4, r0 = 0, c0 = 0
Output: [[0,0],[0,1],[0,2],[0,3]]

NOTE: The critical of problem is: len ++ at west and east dir.
      The turn right can be represented as "Cross Product".

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r, int c) {
        int current_dir = 0; // dir start at the east
        int path_len = 1; 
        vector<vector<int>> path;

        while(path.size()< R * C){
            for(int i=0; i<path_len; i++){
                if(!( r<0 || r>=R || c<0 || c>=C)) 
                    path.push_back({r, c}); // check whether point valid.
                r += dir[current_dir][0];  // Go Next Location. 
                c += dir[current_dir][1];
            }

            current_dir = (current_dir + 1) % 4; // change direction. 
            if (current_dir == 0 || current_dir == 2){
                path_len += 1;
            }
        }
        return path;
    }
private:
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // east, south, west, north
};

int main(){
    cout << "Hello, world!" << endl;
    Solution solu;
    auto path = solu.spiralMatrixIII(5, 6, 1, 4);
    for(int i=0; i<path.size(); i++){
        cout << path[i][0] << ' ' << path[i][1] << endl;
    }
}