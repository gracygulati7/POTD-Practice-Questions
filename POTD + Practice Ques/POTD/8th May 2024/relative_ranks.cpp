//! Leetcode Question 506. Relative Ranks

//? link: https://leetcode.com/problems/relative-ranks/description/?envType=daily-question&envId=2024-05-08

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> temp = score; // Create a temporary copy of the score array
        sort(temp.rbegin(), temp.rend()); // Sort the temp array in descending order

        vector<string> medals = {"Gold Medal", "Silver Medal", "Bronze Medal"}; // Create a vector to hold the medal names
        unordered_map<int, string> rank; // Create an unordered map to store ranks

        // Loop through the sorted scores(temp) to assign ranks
        for (int i = 0; i < temp.size(); i++) {
            // Assign medals to top three scores, and ranks to others
            if (i < 3) rank[temp[i]] = medals[i];
            else rank[temp[i]] = to_string(i + 1); // Convert rank to string
        }
        vector<string> answer(score.size()); // Create a vector to store the final ranks

        // Loop through the original scores to fetch ranks from the map
        for (int i = 0; i < score.size(); i++) {
            answer[i] = rank[score[i]]; // Assign rank from the map
        }
        return answer; // Return the vector containing ranks
    }
};
int main(){
    Solution sol;
    vector<int> score = {5, 4, 3, 2, 1};
    vector<string> answer = sol.findRelativeRanks(score);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }
    return 0;
}