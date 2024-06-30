/*Find the first non-repeating element in a given array arr of n integers and if there is not present any non-repeating element then return 0

Note: The array consists of only positive and negative integers and not zero.*/

class Solution{
    public:
    int firstNonRepeating(int arr[], int n) 
    { 
        // Complete the function 
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
    for(int i=0;i<n;i++){
        int key=arr[i];
        auto flag=mp.find(key);
        if(flag->second==1){
            return key;
        }
    }
        return 0;
    } 
  
};