#include<iostream>
#include<vector>
using namespace std;

void sortarr(vector<int>&nums,int n){

    int count0=0;
    int count1=0;
    int count2=0;

    for(int i=0;i<n;i++){
        if(nums[i]==0){
            count0++;
        }
        else if(nums[i]==1){
            count1++;
        }
        else{
            count2++;
        }
    }

    for(int i=0;i<count0;i++){
        nums[i]=0;
    }
    for(int i=count0;i<count0+count1;i++){
        nums[i]=1;
    }
    for(int i=count1+count0;i<n;i++){
        nums[i]=2;
    }
}

int main(){

    int n=6;
    vector<int>nums={0,2,1,2,0,1};
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    sortarr(nums,n);
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}