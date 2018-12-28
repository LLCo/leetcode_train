/*
In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.

The given input is a directed graph that started as a rooted tree with N nodes (with distinct values 1, 2, ..., N), with one additional directed edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] that represents a directed edge connecting nodes u and v, where u is a parent of child v.

Return an edge that can be removed so that the resulting graph is a rooted tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given directed graph will be like this:
  1
 / \
v   v
2-->3
Example 2:
Input: [[1,2], [2,3], [3,4], [4,1], [1,5]]
Output: [4,1]
Explanation: The given directed graph will be like this:
5 <- 1 -> 2
     ^    |
     |    v
     4 <- 3
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {

        //Search the node that has two edge point it. And the two edges.
        bool flag = false;
        vector<int> edgeA, edgeB, parents(edges.size() + 1, 0);

        for(auto & edge : edges){
            if(parents[edge[1]] == 0){
              parents[edge[1]] = edge[0];
            }else{ // don't add edgB into the parent graph.
                edgeA = {parents[edge[1]], edge[1]};
                edgeB = edge;
                edge[0] = 0;
            }
        }

        // Find two edge point, Try to delete the edgeB, and then test this graph to known whether it's rooted tree.
        for(int i=0; i<edges.size()+1; i++) parents[i] = i;

        for(auto edge : edges){
            if(edge[0] == 0) continue;
            int r = root(parents, edge[0]);
            if(r == edge[1]){ // make up the hoops.
                if (!edgeB.empty()) return edgeA;
                return edge;
            }
            parents[edge[1]] = r;
        }
        return edgeB;
    }

    int root(vector<int> parents, int k){
      if(k!=parents[k]){
        parents[k] = root(parents, parents[k]);
      }
      return parents[k];
    }
};

int main(){
  vector<vector<int>> a = {{1, 2}, {1, 3}, {2, 3}};
  vector<vector<int>> b = {{1, 2}, {2, 3}, {3, 1}, {4, 1}};
  vector<vector<int>> c = {{1, 2}, {2, 3}, {3, 1}, {1, 4}};
  vector<vector<int>> d = {{4, 2}, {1, 5}, {5, 2},{5, 3}, {2, 4}};

  Solution solu;
  auto egde = solu.findRedundantDirectedConnection(d);
  cout << egde[0] << ' ' << egde[1] << endl;
  return 0;
}
