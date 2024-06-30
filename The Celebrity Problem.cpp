/*to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Return the index of the celebrity, if there is no celebrity return -1.
Note: Follow 0 based indexing.
Follow Up: Can you optimize it to O(N)
*/

//User function template for C++

class Solution 
{
    private:
    bool knows(vector<vector<int> >& M,int a,int b){
        if(M[a][b]==1)
            return true;
        else
            return false;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int>st;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        
        while(st.size()>1){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            
            if(knows(M,a,b)){
                st.push(b);
            }else{
                st.push(a);
            }
        }
        int ans=st.top();
        //row  check
        int countzero=0;
        // bool rowval=false;
        for(int i=0;i<n;i++){
            if(M[ans][i]==0){
                countzero++;
            }
        }
        
        if(countzero!=n){
            return -1;
        }
        //col check
        int countone=0;
        // bool colval=false;
        for(int i=0;i<n;i++){
            if(M[i][ans]==1){
                countone++;
            }
        }
        
        if(countone!=n-1){
            return -1;
        }
        
        // if(rowval==true && colval==true)
            return ans;
        // else
            // return -1;
    }
};