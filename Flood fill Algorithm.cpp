/*An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.*/


class Solution {
private:
    void dfs(vector<vector<int>>& image,vector<vector<int>>& ans,
    int sr,int sc,int init,int newColor,
    vector<int>&delrow,vector<int>&delcol){
        ans[sr][sc]=newColor;
        int n=image.size();
        int m=image[0].size();
        
        for(int i=0;i<4;i++){
            int nsr=sr+delrow[i];
            int nsc=sc+delcol[i];
            
            if(nsr>=0 && nsr<n && nsc>=0 && nsc<m && 
            ans[nsr][nsc]!=newColor && image[nsr][nsc]==init){
                dfs(image,ans,nsr,nsc,init,newColor,delrow,delcol);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        vector<vector<int>>ans=image;
        int init=image[sr][sc];
        vector<int>delrow={-1,0,1,0};
        vector<int>delcol={0,1,0,-1};
        dfs(image,ans,sr,sc,init,newColor,delrow,delcol);
        return ans;
    }
};


