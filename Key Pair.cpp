/*Given an array Arr of N positive integers and another number X. Determine whether or not there exist two elements in Arr whose sum is exactly X.*/

//User function template for C++
class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
	    unordered_map<int,int>mp;
	    for(int i=0;i<n;i++){
	        mp[arr[i]]++;
	    }
	    
	    for(auto itr=mp.begin();itr!=mp.end();itr++){
	        int key=itr->first;
	        int val=itr->second;
	        
	        int pair=x-key;
	        
	        if(key==pair){
	            if(val>1){
	                return true;
	            }
	        }else if(mp.find(pair)!=mp.end()){
	            return true;
	        }
	    }
	    return false;
	}
};