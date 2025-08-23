#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print(vector<vector<int>>&output){
    cout<<"the unique subset"<<endl;
    cout<<"[";
    for(int i=0;i<output.size();i++){
        cout<<"[";
        for(int j=0;j<output[i].size();j++){
            cout<<output[i][j]<<" ";
        }
        cout<<"]";
    }
    cout<<"]"<<endl;
}
class Solution{

    private:
    void subseting(int index,vector<int>&nums,vector<int>&store,vector<vector<int>>&output){
        output.push_back(store);

        for(int i=index;i<nums.size();i++){
            if(i!=index && nums[i]==nums[i-1])
            continue;
            store.push_back(nums[i]);
            subseting(i+1,nums,store,output);
            store.pop_back();
        }
    }
    public:
    vector<vector<int>>subset(vector<int>&nums){
        vector<vector<int>>output;
        vector<int>store;
        sort(nums.begin(),nums.end());
        subseting(0,nums,store,output);
        return output;
    }
};

int main(){

    Solution obj;
    vector<int>nums={1,2,2};
    vector<vector<int>>output=obj.subset(nums);
    print(output);
}