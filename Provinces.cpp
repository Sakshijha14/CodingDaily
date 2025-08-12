#include<iostream>
#include<vector>

using namespace std;


class Solution {


    private:

    void dfs(int index,int visited[],vector<int>adjList[]){
        visited[index]=1;
        for(auto it:adjList[index]){
            if(!visited[it]){
                dfs(it,visited,adjList);
            }
        }
    }
    public:

    int numprovinces(vector<vector<int>>adj){
       const  int V=3;
        vector<int>adjList[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int visited[V]={0};
        int count=0;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                count++;
                dfs(i,visited,adjList);
            }
        }
        return count;

    }

};

int main(){
    vector<vector<int>>adj={
        {1,0,1},
        {0,1,0},
        {1,0,1}
    };
    Solution ob;
    cout<<"the number of provinces of islands: "<<ob.numprovinces(adj)<<endl;
}