//! GeeksForGeeks Question Nearly sorted

//? link: https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1

//* LOGIC: Merge Sort for time complexity of o(nlogn)

#include<bits/stdc++.h>
using namespace std;
class Solution {
    public: 
    vector <int> nearlySorted(int arr[], int num, int K){
        mergesort(arr,0,num-1); vector<int> res(arr,arr+num);
        return res;
    }
    void mergesort(int arr[],int left,int right){
        if(left<right){
            int mid=left+(right-left)/2; // Calculate the middle index

            // Recursively sort the left and right halves
            mergesort(arr,left,mid);
            mergesort(arr,mid+1,right);

            merge(arr,left,mid,right); // Merge the sorted halves
        }
    }
    void merge(int arr[],int left,int mid,int right){
        int n1=mid-left+1; int n2=right-mid; // Size of the left and right subarrays
        vector<int> l(n1),r(n2); // Create temporary arrays to store left and right subarrays

        // Copy data to temporary arrays
        for(int i=0;i<n1;i++){
            l[i]=arr[left+i];
        }
        for(int i=0;i<n2;i++){
            r[i]=arr[mid+1+i];
        }

        // Merge the temp arrays back into arr[left..right]
        // i is initial index of left subarray, j is initial index of right subarray, k is initial index of merged subarray
        int i=0,j=0,k=left; 
        
        while(i<n1 && j<n2){
            if(l[i]<=r[j]){
                arr[k]=l[i];
                i++;
            }
            else{
                arr[k]=r[j];
                j++;
            }
            k++;
        }

        // Copy the remaining elements of L[], if any
        while(i<n1){
            arr[k]=l[i]; 
            i++; k++;
        }
        // Copy the remaining elements of R[], if any
        while(j<n2){
            arr[k]=r[j]; 
            j++; k++;
        }
    }
};
int main(){
    int t; cin>>t;
    while(t--){
        int num,k; cin>>num>>k;
        int arr[num];
        for(int i=0;i<num;i++){
            cin>>arr[i];
        }
        Solution s;
        vector<int> res=s.nearlySorted(arr,num,k);

        // Print the sorted array
        for(int i=0;i<num;i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}