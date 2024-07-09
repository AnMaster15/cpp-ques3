#include<iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;

    }


};
//tree banane ke liye
node* buildtree(node* root){
    cout<<"enter the data: "<<endl;
    int data;
    cin>>data;
    root=new node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"enter the data for inserting in left"<<endl;
    root->left=buildtree(root->left);

    cout<<"enter the data for inserting in right"<<endl;
    root->right=buildtree(root->right);

    return root;

}
//tree show karene kwe liye
void levelordertraversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);//seperator

    while(!q.empty()){
        node* temp =q.front();
      
        q.pop();

        if(temp==NULL){//purane level compltee
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
              cout<<temp->data<<" ";

            if(temp->left){
            q.push(temp->left);
        }
         if(temp->right){
            q.push(temp->right);
        }

        }
        
    }
}



void noleaf(node* root,int &count){
    if(root== NULL){
        return;
    }
    noleaf(root->left,count);
    //leaf node 
    if(root->left==NULL && root->right==NULL){
        count++;
    }
  noleaf(root->right,count);
}
int noOfLeafNodes(node *root){
  int count=0;
 noleaf(root,count);
  return count;


}
bool isbst(node* &root,int min,int max){

    //base case

    if(root==NULL){
        return true;
    }
    if(root->data>min&&root->data<=max){
        bool left=isbst(root->left, min,root->data);
        bool right=isbst(root->right,root->data,  max);
        return left &&right;
    }
    else{
        return false;
    }
}
bool validateBST(node* &root) {
  
    return isbst(root,INT_MIN,INT_MAX);
}
//1 5 7 3 9 2 -1 //4 
//5 8 3 78 53 12 89 4 -1 //5
int main(){

    node* root=NULL;

    root=buildtree(root);
    
    //1 2 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    levelordertraversal(root);
    
    // bool ans=validateBST(root);
    
    // if(ans==true){
    //     cout<<"yes"<<endl;
    // }
    // else{
    //     cout<<"no"<<endl;
    // }
    // cout<<noOfLeafNodes(root);

    // cout<<" inorder transversal is: "<<endl;
    // inorder(root);

    //  cout<<" preorder transversal is: "<<endl;
    // preorder(root);

    
    //  cout<<" postrder transversal is: "<<endl;
    // postorder(root);

// buildfromlevelorder(root);


    return 0;
}


































//tree banane ke liye 2
// void buildfromlevelorder(node* &root){
//     queue<node*>q;
//     cout<<"enter data for root"<<endl;
//     int data;
//     cin>>data;
//     root=new node(data);
//     q.push(root);

//     while(!q.empty()){
//         node* temp=q.front();
//         q.pop();

//         cout<<"enter left node data for: "<<temp->data<<endl;

//         int leftdata;
//         cin>>leftdata;

//         if(leftdata != -1){
//             temp->left=new node(leftdata);
//             q.push(temp->left);
//         }

//         cout<<"enter right node data for: "<<temp->data<<endl;

//         int rightdata;
//         cin>>rightdata;

//         if(rightdata != -1){
//             temp->right=new node(rightdata);
//             q.push(temp->right);
//         }
//     }

