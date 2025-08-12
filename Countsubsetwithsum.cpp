#include<iostream>
#include<vector>

using namespace std;

int countways(vector<int>&arr,int k){

    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(k+1,0));

    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }
    if(arr[0]<=k){
        dp[0][arr[0]]=1;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<=k;j++){
            int notake=dp[i-1][j];
            int take=0;
            if(arr[i]<=j){
                take=dp[i-1][j-arr[i]];
            }

            dp[i][j]=take+notake;
        }
    }
    return dp[n-1][k];
}

using namespace std;

int main(){
    vector<int>arr={1,2,2,3};
    int k=3;
    cout<<"the number of ways to have this sum: "<<countways(arr,k)
<<endl;}