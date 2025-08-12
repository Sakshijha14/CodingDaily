#include<iostream>
#include<vector>

#include <climits> 
using namespace std;

int gridsum(int n,int m,vector<vector<int>>&grid,vector<vector<int>>&dp){

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                dp[i][j]=grid[i][j];
                continue;
            }
            int up=INT_MAX;
            int left=INT_MAX;
            if(i>0){
                up=grid[i][j]+dp[i-1][j];
            }
            if(j>0){
                left=grid[i][j]+dp[i][j-1];
            }

            dp[i][j]=min(up,left);

        }
    }
    return dp[n-1][m-1];
}

int summing(int n,int m,vector<vector<int>>grid){
    vector<vector<int>>dp(n,vector<int>(m,0));

    return gridsum(n,m,grid,dp);
}

using namespace std;

int main(){

    vector<vector<int>>grid={
        {5,9,6},
        {11,5,2}
    };

    int n=grid.size();
    int m=grid[0].size();

    cout<<"the sum : "<<summing(n,m,grid)<<endl;
}