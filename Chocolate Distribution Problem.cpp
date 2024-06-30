/*Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are M students, the task is to distribute chocolate packets among M students such that :
1. Each student gets exactly one packet.
2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum.*/

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        sort(a.begin(),a.end());
        int i=0;
        int j=m-1;
        int mini=INT_MAX;
        while(j<a.size()){
            int dif=a[j]-a[i];
            mini=min(dif,mini);
            i++;
            j++;
        }
        return mini;
    }   
};