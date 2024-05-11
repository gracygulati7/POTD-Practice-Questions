//! LeetCode Question 264. Ugly Number II

//? link: https://leetcode.com/problems/ugly-number-ii/description/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) return 0; // Edge case

        vector<int> ugly(n); // Initialize a vector to store ugly numbers
        ugly[0] = 1; // First ugly number is 1
        int i2 = 0, i3 = 0, i5 = 0; // Pointers for multiples of 2, 3, and 5

        for (int i = 1; i < n; i++) {
            // Find the next ugly number by multiplying the previous ugly numbers with 2, 3, and 5
            int nextUgly = min({ugly[i2] * 2, ugly[i3] * 3, ugly[i5] * 5});
            ugly[i] = nextUgly;

            // Update pointers for multiples of 2, 3, and 5 based on which one was chosen
            if (nextUgly == ugly[i2] * 2) i2++;
            if (nextUgly == ugly[i3] * 3) i3++;
            if (nextUgly == ugly[i5] * 5) i5++;
        }
        return ugly[n - 1]; // Return the nth ugly number
    }
};
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        Solution s;
        cout<<s.nthUglyNumber(n)<<endl;
    }
    return 0;
}