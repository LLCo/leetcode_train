#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
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

int main(){
	Solution solution;
	// {{1,3},{3,0,1},{2},{0}}, {{1},{2},{3},{}}
	vector<vector<int>> v({{}, {1}});
	cout << solution.canVisitAllRooms(v);
}


/*
#include <iostream>
 
using namespace std;
 
int main(void)
{
        cout<<"Hello World!"<<endl;
        return 0;
}
*/
