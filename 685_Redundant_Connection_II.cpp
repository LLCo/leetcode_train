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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {

        //Search the node that has two edge point it. And the two edges.
        vector<int> search(edges.size() + 1, -1);
        int node, i=0;
        bool flag = false;
        int m;
        vector<int> edgeA, edgeB;

        for(auto edge : edges){
            if(search[edge[1]] == -1){
              search[edge[1]] = edge[0];
            }else{
                edgeA = {search[edge[1]], edge[1]};
                edgeB = edge;
                flag = true;
                break;
            }
            i++; // use to recode the location of egdeB
        }

        // Find two edge point, Try to delete the edgeB, and then test this graph to known whether it's rooted tree.
        if(flag){ 
          edges.erase(edges.begin() + i); // delete edgeB from graph. 
          if(isRootedTree(edges)) return edgeB;
          return edgeA;
        }else{ // To find the hoop;
          auto hoops = get_hoops(search);
          for(int i=0; i<edges.size(); ++i){
            for(auto hoop : hoops){
              if(edges[edges.size() - 1 - i][0] == hoop[0] && edges[edges.size() - 1 - i][1] == hoop[1]) return hoop;
            }
          }
        }
        return {0, 0};
    }

    vector<vector<int>> get_hoops(vector<int>& parents){
      
      int node = parents[1];
      vector<vector<int>> hoops;
      // enter the hoop
      int i=0;
      while(i++<parents.size()){ 
        node = parents[node];
      }

      // save the hoop
      int start = node;
      node=parents[node];
      while (node != start){
        hoops.push_back({parents[node], node});
        node=parents[node];
      }

      // return the hoops
      return hoops;
    }

    bool isRootedTree(vector<vector<int>>& edges){
      // search root. 
      int root_num = 0;
      vector<bool> search(edges.size() + 1, false);
      for(auto edge : edges){
        search[edge[1]] = true;
      }
      for(auto num : search){
        root_num += num;
      }

      return root_num == edges.size() - 1;
    }
};

int main(){
  vector<vector<int>> a = {{1, 2}, {1, 3}, {2, 3}};
  vector<vector<int>> b = {{1, 2}, {2, 3}, {3, 1}, {4, 1}};
  vector<vector<int>> c = {{1, 2}, {2, 3}, {3, 1}, {1, 4}};

  Solution solu;
  auto egde = solu.findRedundantDirectedConnection(b);
  cout << egde[0] << ' ' << egde[1] << endl;
  return 0;
}
