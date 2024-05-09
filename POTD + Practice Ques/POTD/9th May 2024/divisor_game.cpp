//! GeeksForGeeks Question Divisor Game

//? link: https://www.geeksforgeeks.org/problems/divisor-game-1664432414/1

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool divisorGame(int n) {
        if(n%2==0) return true;
        return false;
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.divisorGame(n)<<endl;
    }
    return 0;
}