/*The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.*/



class Solution {
public:

    vector<vector<string>>ans;

    bool safe(int row,int col,vector<vector<int>> &board,int n){
        
        //traverse row
        int x=row,y=col;
        while(y>=0){
            if(board[x][y]==1){
                return false;
            }
            y--;
        }

        //traverse up diagonal
        x=row,y=col;
        while(y>=0 && x>=0){
            if(board[x][y]==1){
                return false;
            }
            x--;
            y--;
        }

        //traversing down diagonal
        x=row,y=col;
        while(y>=0 && x<n){
            if(board[x][y]==1){
                return false;
            }
            x++;
            y--;
        }
        return true;
    }

    void addelement(vector<vector<int>> &board,int n){
        vector<string>hold;
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=0;j<n;j++){
                if(board[i][j]==1){
                    temp=temp+'Q';
                }else {
                    temp=temp+'.';
                }
            }
            hold.push_back(temp);
        }
        ans.push_back(hold);
    }

    void solve(int col,vector<vector<int>> &board,int n){
        if(col==n){
            addelement(board,n);
            return;
        }

        for(int row=0;row<n;row++){
            if(safe(row,col,board,n)){
                board[row][col]=1;
                solve(col+1,board,n);
                board[row][col]=0;
            }

        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>>board(n,vector<int>(n,0));

        solve(0,board,n);

        return ans;
    }
};


/*
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

*/