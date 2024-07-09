#include<iostream>
#include<queue>
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

node* insertintobst(node* &root,int d){

    if(root ==NULL){
        root =new node(d);
        return root;
    }

    if(d>root->data){
        root->right=insertintobst(root->right,d);


    }
    else{
        root->left=insertintobst(root->left,d);


    }
    return root;

}

void takeinput(node* &root){
    int data;
    //cout<<"enter the value for node"<<endl;
    cin>>data;

    while(data!= -1){
        insertintobst(root,data);
        cin>>data;
    }
}
//recurtion
// bool searchInBST(node* &root, int x) {
//     // Write your code here.

//     if(root ==NULL){
//         return false;
//     }

//     if(root->data==x){
//         return true;
//     }

//     if(root->data>x){
//         return searchInBST(root->left,x);
//     }
//     else{
//         return searchInBST(root->right,x);
//     }
// }

bool searchInBST(node* root,int x){

    node *temp=root;
    while(temp !=NULL){
        if(temp->data==x){
            return true;

        }

        if(temp->data>x){
            temp=temp->left;

        }else{
            temp=temp->left;
        }

    }
    return false;
}

node* min(node* root){
    node* temp=root;

    while(temp->left !=NULL){
        temp=temp->left;
    }
    return temp;
}
node* max(node* root){
    node* temp=root;

    while(temp->right !=NULL){
        temp=temp->right;
    }
    return temp;
}

node* deletefrombst(node* root,int element){

    if(root==NULL){
        return root;
    }

    if(root->data==element){

        //0 child

        if(root->left==NULL&& root->right==NULL){
            delete root;
            return NULL;
        }

        //1 child

        //LEFT CHILD

        if(root->left !=NULL&& root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;
        }

        //right child

        if(root->left ==NULL&& root->right!=NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }



        //2 child

        if(root->left !=NULL&& root->right!=NULL){
            int mini=min(root->right)->data;
            root->data=mini;
            root->right=deletefrombst(root->right,mini);
            return root;
        }


    }
    else if(root->data>element){
        root->left=deletefrombst(root->left,element);

    }
    else{
          root->right=deletefrombst(root->right,element);

    }
    return root;

}



int main(){

    node* root=NULL;

    cout<<"enter data to create bst"<<endl;
    takeinput(root);

    cout<<"printing the bst"<<endl;

    levelordertraversal(root);

    bool a=searchInBST(root,8);
    if(a==true){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }

    return 0;
}