#include<iostream>
#include<vector>
using namespace std;

vector<int>elementsign(vector<int>&num){
    int n=num.size();
    vector<int>output(n,0);

    int possitive=0;
    int negative=1;
    for(int i=0;i<n;i++){
        if(num[i]<0){
        output[negative]=num[i];
        negative+=2;
        }
        else{
            output[possitive]=num[i];
            possitive+=2;
        }
    }

    return output;
}

int main(){

    vector<int>num={1,2,-4,-5};
    vector<int>output=elementsign(num);

    for(int i=0;i<output.size();i++){
        cout<<output[i]<<" ";
    }

    return 0;
}