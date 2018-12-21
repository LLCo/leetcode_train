/*
There are N rooms and you start in room 0.  Each room has a distinct number in 0, 1, 2, ..., N-1, and each room may have some keys to access the next room. 

Formally, each room i has a list of keys rooms[i], and each key rooms[i][j] is an integer in [0, 1, ..., N-1] where N = rooms.length.  A key rooms[i][j] = v opens the room with number v.

Initially, all the rooms start locked (except for room 0). 

You can walk back and forth between rooms freely.

Return true if and only if you can enter every room.

Example 1:

Input: [[1],[2],[3],[]]
Output: true
Explanation:  
We start in room 0, and pick up key 1.
We then go to room 1, and pick up key 2.
We then go to room 2, and pick up key 3.
We then go to room 3.  Since we were able to go to every room, we return true.
Example 2:

Input: [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can't enter the room with number 2.
Note:

1 <= rooms.length <= 1000
0 <= rooms[i].length <= 1000
The number of keys in all rooms combined is at most 3000.

*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution { // 4ms, 100%
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // cout<< "Hello, world!" << endl;
		
		int room_num = rooms.size();
		vector<bool> visited_room(room_num, 0);
		visit(0, visited_room, rooms);
		// cout<< rooms[0][0] << visited_room[0] << endl;
		
		for(auto is_visited:visited_room){
			if(!is_visited){
				return false;  // Return false if one room hasn't been visited!
			}
		}
		return true;
    }
	
	void visit(int loc, vector<bool>& visited_room, vector<vector<int>>& rooms){
		visited_room[loc] = true; // make current room visited!
		auto keys = rooms[loc]; // get keys of current rooms. 
		for(auto i_keys:keys){
			if(visited_room[i_keys] == false){ // if not visit.
				visit(i_keys, visited_room, rooms);  // visit!
			}
		}
	}
};

/*
int main(){
	Solution solution;
	// {{1,3},{3,0,1},{2},{0}}, {{1},{2},{3},{}}
	vector<vector<int>> v({{}, {1}});
	cout << solution.canVisitAllRooms(v);
}
*/
