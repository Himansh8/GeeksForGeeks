/*Given an array arr[] of size n, find the first repeating element. The element should occur more than once and the index of its first occurrence should be the smallest.

Note:- The position you return should be according to 1-based indexing. */

// User function template in C++

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        // code here
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++){
            int key=arr[i];
            mp[key]++;
        }
        
        for(int i=0;i<n;i++){
            int key=arr[i];
            auto temp=mp.find(key);
            if(temp->second>1){
                return i+1;
            }
        }
        return -1;
    }
};