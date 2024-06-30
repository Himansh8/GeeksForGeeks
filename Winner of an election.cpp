/*Given an array of n names arr of candidates in an election, where each name is a string of lowercase characters. A candidate name in the array represents a vote casted to the candidate. Print the name of the candidate that received the maximum count of votes. 
If there is a draw between two candidates, then print lexicographically smaller name.*/

//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        unordered_map<string,int>mp;
        vector<string>ans;
        
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        string name="";
        int max=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            string key=it->first;
            int count=it->second;
            if(count>max){
                max=count;
                name=key;
            }else if(count==max){
                if(key<name){
                    name=key;
                }
            }
        }
        
        ans.push_back(name);
        string temp=to_string(max);
        ans.push_back(temp);
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}

// } Driver Code Ends