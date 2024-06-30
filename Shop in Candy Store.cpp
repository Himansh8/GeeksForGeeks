/*In a candy store, there are N different types of candies available and the prices of all the N different types of candies are provided to you.
You are now provided with an attractive offer.
For every candy you buy from the store and get K other candies ( all are different types ) for free.
Now you have to answer two questions. Firstly, you have to find what is the minimum amount of money you have to spend to buy all the N different candies. Secondly, you have to find what is the maximum amount of money you have to spend to buy all the N different candies.
In both the cases you must utilize the offer i.e. you buy one candy and get K other candies for free.*/


class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        sort(candies,candies+N);
        
        int mini=0;
        int buy=0;
        int muft=N-1;
        
        while(buy<=muft){
            mini=mini+candies[buy];
            buy++;
            muft=muft-K;
        }
        
        int max=0;
        buy=N-1;
        muft=0;
        
        while(muft<=buy){
            max=max+candies[buy];
            buy--;
            muft=muft+K;
        }
        
        vector<int>ans;
        ans.push_back(mini);
        ans.push_back(max);
        
        return ans;
    }
};