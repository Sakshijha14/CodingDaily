#include<iostream>
#include<vector>
using namespace std;

int counting(int n,int m,vector<vector<int>>&grid,vector<vector<int>>&dp){

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if( grid[i][j]==-1){
                dp[i][j]=0;
                continue;
            }
            if(i==0 && j==0){
                dp[i][j]=1;
                continue;
            }

            int up=0,left=0;
            if(i>0){
                up=dp[i-1][j];
            }
            if(j>0){
                left=dp[i][j-1];
            }

            dp[i][j]=up+left;
        }
    }
    return dp[n-1][m-1];
}

int gridunique(int n,int m,vector<vector<int>>&grid){

    vector<vector<int>>dp(n,vector<int>(m,0));
    return counting(n,m,grid,dp);
}

int main(){

    vector<vector<int>>grid{
        {0,0,0},
        {0,-1,0},
        {0,0,0}
    };
    int n=grid.size();
    int m=grid[0].size();

    cout<<"Unique Paths with Ostacles: "<<gridunique(n,m,grid)<<endl;


}