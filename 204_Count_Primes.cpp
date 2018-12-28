/*

Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Note:
使用筛数法进行合数的剔除，其思想为：一个能整除比他小的质数的数就是合数。

算法中，使用 from 质数 i * i step i 的方式，通过取下标来去除合数。
这里的重点是被去除的数从i * i开始数。

当算法取到小于等于sqrt(n)后，剩下的数就都是质数了，这样可以避免很多不必要的计算。
*/

#include <iostream>
#include <list>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n, true);
        primes[0] = false, primes[1] = false, primes[2] = true;
        int last_prime = 0;
        while(last_prime < sqrt(n)){
            for(++last_prime; primes[last_prime] != true; ++last_prime);
            for(int i=last_prime*last_prime; i < n; i += last_prime){
                primes[i] = false;
            }
        }
        int sum = 0;
        for(int i=0; i<primes.size(); i++){
            if(primes[i]) sum ++;
        }
        return sum;
    }
};

int main(){
    int a = 999983;
    // cin >> a;
    Solution solu;
    cout << solu.countPrimes(a) << endl;
}