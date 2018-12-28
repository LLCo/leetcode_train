#include <iostream>
#include <vector>
#include <list>
#include<time.h>
#include <unordered_map>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        list<int> prime_list;
        for(int i=2; i<n; ++i){
            prime_list.push_back(i);
        }
        list<int>::iterator p_last_prime, p_iter;
        while(p_last_prime != prime_list.end()){
            
            p_last_prime = prime_list.begin();
            p_iter = prime_list.begin();
            p_iter++;
            while(p_iter != prime_list.end()){
                if(*p_iter % *p_last_prime == 0){
                    p_iter = prime_list.erase(p_iter);
                }else{
                    ++p_iter;
                }
            }:
            p_last_prime ++ ;
        }
        for(p_last_prime = prime_list.begin(), p_iter = p_last_prime + 1; ){
            
        }


        return 0;
    }

    void sieve(vector<int> arr, int prime){
        for(int i = prime+1; i<arr.size(); ++i){
            if(arr[i] == 1) continue;
            if(arr[i] % prime == 0) 
        }
    }


private:
    vector<int> arr;
};

int main(){
    int a = 15;
    Solution solu;
    cout << solu.countPrimes(a) << endl;
}