#include<iostream>
#include<vector>
using namespace std;

int counting(int n,int m,vector<vector<int>>&dp){

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                dp[i][j]=1;
                continue;
            }
            int up=0;
            int left=0;

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

int unique(int m,int n){
    vector<vector<int>>dp(m,vector<int>(n,0));
    return counting(m,n,dp);
}

int main(){
    int m=3;
    int n=2;

    cout<<"No. of unique ways to reach destination: "<<unique(m,n)<<endl;
}