#include<iostream>
#include<vector>


using namespace std;

int gridsum(int n,vector<vector<int>>&grid){
    vector<vector<int>>dp(n,vector<int>(n,0));
    
    for(int j=0;j<n;j++){
        dp[n-1][j]=grid[n-1][j];
    }
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<grid[i].size();j++){
            int down=grid[i][j]+dp[i+1][j];
            int downright=grid[i][j]+dp[i+1][j+1];
            dp[i][j]=min(down,downright);
        }
    }
    return dp[0][0];
}

int main(){
    vector<vector<int>>grid={
        {1},
        {2,3},
        {3,6,7},
        {8,9,6,10}
    };
    int n=grid.size();
    cout<<"the sum of it is: "<<gridsum(n,grid)<<endl;
}