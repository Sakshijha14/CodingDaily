#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node*left;
    Node*right;
    Node(int x):data(x),left(NULL),right(NULL){}
};

class Solution{

    public:
    int widthofbinarytree(Node*head){
        if(!head){
            return 0;
        }
        int output=0;
        queue<pair<Node*,int>>q;

        q.push({head,0});

        while(!q.empty()){
            int size=q.size();
            int minindi=q.front().second;
            int first;
            int end;
            for(int i=0;i<size;i++){

                int present=q.front().second-minindi;
                Node*node=q.front().first;
                q.pop();

                if(i==0){
                    first=present;
                }
                if(i==size-1){
                    end=present;
                }
                if(node->left){
                    q.push({node->left,2*present+1});
                }

                if(node->right){
                    q.push({node->right,2*present+2});
                }
            }

            output=max(output,end-first+1);

        }
        return output;
    }
};

int main(){

    Node*head=new Node(1);
    head->left=new Node(2);
    head->right=new Node(3);
    head->left->left=new Node(4);
    head->left->right=new Node(5);
    head->right->right=new Node(6);

    Solution obj;
    cout<<"Maximum width of the binary tree is: "<<obj.widthofbinarytree(head)<<endl;

    return 0;
}