/*
In this problem, a tree is an undirected graph that is connected and has no cycles.

The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), with one additional edge added. 
The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] with u < v, that represents an undirected 
edge connecting nodes u and v.

Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there are multiple answers, return the answer 
that occurs last in the given 2D-array. The answer edge [u, v] should be in the same format, with u < v.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given undirected graph will be like this:
  1
 / \
2 - 3
Example 2:
Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
Output: [1,4]
Explanation: The given undirected graph will be like this:
5 - 1 - 2
    |   |
    4 - 3
Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.

*/

#include <iostream>
#include <vector>

using namespace std;

class UnionFindSet {
public:
  UnionFindSet(int n):set(n){
    for(int i=0; i<n; i++) set[i] = i;
  }

  int find(int x){
    if (set[x] != x) set[x] = find(set[x]);
    return set[x];
  }

  void union_(int x, int y){
    set[find(y)] = find(x);
  }
private:
  vector<int> set;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFindSet ufs(edges.size() + 1);
        vector<int> last_edge;
        for(auto edge : edges){
          if(ufs.find(edge[0]) == ufs.find(edge[1])){
            last_edge = edge;
          }else{
            ufs.union_(edge[0], edge[1]);
          }
        }
        return last_edge;
    }
};

int main(){
  vector<vector<int>> a = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
  Solution solu;
  auto egde = solu.findRedundantConnection(a);
  cout << egde[0] << ' ' << egde[1] << endl;
  return 0;
}

