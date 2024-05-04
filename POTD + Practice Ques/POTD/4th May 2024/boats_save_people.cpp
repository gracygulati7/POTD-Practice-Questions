//! Leetcode Question 881. Boats to Save People

//? link: https://leetcode.com/problems/boats-to-save-people/description/?envType=daily-question&envId=2024-05-04

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boat = 0; // Initialize the variable to count the number of boats
        sort(people.begin(), people.end());  // Sort the people vector in ascending order
        
        // Initialize two pointers for the leftmost and rightmost elements of the sorted vector
        int left = 0, right = people.size() - 1;
        
        // Iterate through the people vector
        while (left <= right) {
            // Calculate the sum of the weights of people at the left and right pointers
            int sum = people[left] + people[right];
            
            // If the sum is less than or equal to the limit
            if (sum <= limit) {
                // Increment the boat count
                boat++;
                // Move the left pointer to the right
                left++;
                // Move the right pointer to the left
                right--;
            } else {
                // If the sum exceeds the limit, only one person can go in the boat,
                // so increment the boat count and move the right pointer to the left
                boat++;
                right--;
            }
        }
        return boat; // Return the total number of boats required
    }
};

int main(){
    Solution s;
    vector<int> v={1,2};
    cout<<s.numRescueBoats(v,3)<<endl;
    return 0;
}