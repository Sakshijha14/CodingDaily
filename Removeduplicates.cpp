#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int remove(vector<int>&arr,int n){

    sort(arr.begin(),arr.end());
    int j=0;
    for(int i=1;i<n;i++){
        if(arr[i]!=arr[j]){
            j++;
            arr[j]=arr[i];
        }
    }
    return j+1;
}

int main(){

    vector<int>arr={1,3,4,2,1,2,0,7,8};
    int n=arr.size();
    cout<<"without duplicates: "<<remove(arr,n)<<endl;
}