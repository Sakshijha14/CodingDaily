#include<iostream>
#include<vector>
using namespace std;

class Solution{

    public:

    void summing(int index,int target,vector<int>&nums,vector<int>&store,vector<vector<int>>&output){
        if(target==0){
            output.push_back(store);
            return ;
        }
        if(index>=nums.size()){
            return;
        }
        if(nums[index]<=target){
            store.push_back(nums[index]);
            summing(index,target-nums[index],nums,store,output);
            store.pop_back();
        }
        summing(index+1,target,nums,store,output);
    }
    vector<vector<int>>combinatisum(vector<int>nums,int target){
        vector<vector<int>>output;
        vector<int>store;
        summing(0,target,nums,store,output);

        return output;
    }
};

int main(){
    Solution obj;
    vector<int>nums{2,3,6,7};
    int target=10;
    vector<vector<int>>output=obj.combinatisum(nums,target);
    for(int i=0;i<output.size();i++){
        for(int j=0;j<output[i].size();j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
}