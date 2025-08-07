#include<iostream>
#include<vector>
#include<climits>
using namespace std;

bool palindrome(int i,int j,string &str){
    while(i<j){
        if(str[i]!=str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int partition(string str){

    int n=str.size();
    vector<int>dp(n+1,0);

    dp[n]=0;
    for(int i=n-1;i>=0;i--){
        int mini=INT_MAX;
        for(int j=i;j<n;j++){
            if(palindrome(i,j,str)){
                int cost=1+dp[j+1];
                mini=min(mini,cost);
            }
        }
        dp[i]=mini;
    }
    return dp[0]-1;

}

int main(){

    string str="BABABCBADCEDE";
    int output=partition(str);
    cout<<output<<endl;
}