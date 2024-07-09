#include<iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node* next;
    int key;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
        this->next=NULL;

    }

};

// int countleft=0;
// int countright=0;

void printtransversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);//seperator
   // ++countleft;
   // ++countright;

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
            //++countleft;
        }
         if(temp->right){
            q.push(temp->right);
            //++countright;
        }
        }
        
    }
    //  cout<<"minheight:"<<endl;
    // cout<<min(countleft,countright)+1<<endl;;

//max height

    // if(countleft>=countright){
    //     cout<<"the maxheight is "<<endl;
    //     cout<<countleft+1<<endl;
    // }
    // else{
    //       cout<<"the maxheight is "<<endl;
    //     cout<<countleft+1<<endl;

    // }
   
}
// int minDepth(node *root)
// {
 
//     if (root == NULL)
//         return 0;
 
    
//     if (root->left == NULL && root->right == NULL)
//     return 1;
   
//     int l = INT_MAX, r = INT_MAX;
    
   
//     if (root->left)
//     l = minDepth(root->left);
 
  
//     if (root->right)
//     r =  minDepth(root->right);
 
 
//     return min(l , r) + 1;
// }

node* insert(node* &root,int d){
    if(root==NULL){
        root=new node(d);
        return root;
    }

    if(d>root->data){
        root->right=insert(root->right,d);
    }
    else{
        root->left=insert(root->left,d);
    }
    return root;

}

void takeinput(node* &root){
   int data;

   cin>>data;

   while(data!=-1){
    insert(root,data);
    cin>>data;
   }
}

void inorder(node* root){
    while(root ==NULL){
        return;
    }
        inorder(root->left);
        cout<<root->data<<" "<<endl;
        inorder(root->right);
        
    
}

void preorder(node* root){
    while(root ==NULL){
        return;
    }
        cout<<root->data<<" "<<endl;
        preorder(root->left);
        preorder(root->right);
        
        
    
}

void postorder(node* root){
    while(root ==NULL){
        return;}
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" "<<endl;;
        
    
}

node* min(node* &root){
    
    node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

node* deletenode(node* root,int element){
    if (root==NULL){
        return root;
    }
    if(root->data==element){
        //0 child
        if(root->left==NULL && root->right==NULL){
         delete root;
         return NULL;
        }
    //1 child

    //left child
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
            root->right=deletenode(root->right,mini);
            return root;
        }
    }
     else if(root->data>element){
        root->left=deletenode(root->left,element);
    }

    else{
          root->right=deletenode(root->right,element);
    }
    return root;


}
// int maxDepth(node* node)
// {
//     if (node == NULL)
//         return 0;
//     else {
//         /* compute the depth of each subtree */
//         int lDepth = maxDepth(node->left);
//         int rDepth = maxDepth(node->right);
 
//         /* use the larger one */
//         if (lDepth > rDepth)
//             return (lDepth + 1);
//         else
//             return (rDepth + 1);
//     }
// }

int findposition(int in[],int element,int n){
    for(int i=0;i<n;i++){
        if(in[i]==element){
            return i;
        }
    }
    return -1;

}

node* solvepre(int in[],int pre[],int &index,int inorderstart,int inorderend,int n){
           
           if(index>=n || inorderstart>inorderend){
            return NULL;
           }
           int element=pre[index++];
           node* root=new node(element);
           int position =findposition(in,element,n);
           //recursive
           root->left=solvepre(in,pre,index,inorderstart,position-1,n);
           root->right=solvepre(in,pre,index,position+1,inorderend,n);
           return root;}             

node*buildtreefrompre(int in[],int pre[],int n){
    int preorderindex=0;
    node*ans=solvepre(in,pre,preorderindex,0,n-1,n);
    return ans;
}

node* solvepost(int in[],int post[],int &index,int inorderstart,int inorderend,int n){
    if(index<0 || inorderstart>inorderend){
            return NULL;
           }
           int element=post[index--];
           node* root=new node(element);
           int position =findposition(in,element,n);
            //recursive
             root->right=solvepost(in,post,index,position+1,inorderend,n);
           root->left=solvepost(in,post,index,inorderstart,position-1,n);
          
           return root;


}
node* buildtreefrompost(int in[],int post[],int n){
    int postorderindex=n-1;
    node*ans =solvepost(in,post,postorderindex,0,n-1,n);
    return ans;
}
void inorder(node* root,vector<int>&in){
    if(root== NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

vector<int>mergearrays( vector<int>&bst1, vector<int>&bst2){
    vector<int>ans(bst1.size()+bst2.size());

    int i=0,j=0,k=0;
    while(i<bst1.size() && j<bst2.size()){
        if(bst1[i]<bst2[j]){
            ans[k++]=bst1[i];
            i++;

        }else{
            ans[k++]=bst2[j];
            j++;

        }

    }

    while(i<bst1.size()){
        ans[k++]=bst1[i++];

    }
    while(j<bst2.size()){
        ans[k++]=bst2[j++];

    }
    return ans;
    
    
}

node* inordertobst(int s,int e,vector<int>&in){
    if(s>e){
        return NULL;
    }

    int mid=(s+e)/2;
    node* root=new node(in[mid]);
    root->left=inordertobst(s,mid-1,in);
    root->right=inordertobst(mid+1,e,in);
    return root;

}

node* mergebst(node* root1,node* root2){

    vector<int>bst1,bst2;
    inorder(root1,bst1);
    inorder(root2,bst2);

    vector<int>mergearray= mergearrays(bst1,bst2);

    int s=0; 
    int e=mergearray.size()-1;
    return inordertobst(s,e,mergearray);



}

void convertintosorteddoublylinkl(node* root,node* &head){
    if(root==NULL){
        return;
    }
    convertintosorteddoublylinkl(root->right,head);

    root->right=head;
    if(head !=NULL){
        head->left=root;

        head=root;

        convertintosorteddoublylinkl(root->left,head);
    }
}

node* megre2linklist(node* head1,node* head2){

    node* head=NULL;
    node* tail=NULL;

    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            if(head==NULL){
                head=head1;
                tail=head1;
                head1=head1->right;
            }
            else{
                tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;

            }
        }
        else{
            if(head==NULL){
                head=head2;
                tail=head2;
                head2=head2->right;

            }
            else{
                tail->right=head2;
                head2->left=tail;
                tail=head2;
                head2=head2->right;

            }

        }
        
    }
    while(head1!=NULL){
        tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;
    
    }
     while(head2!=NULL){
        tail->right=head2;
                head2->left=tail;
                tail=head2;
                head1=head2->right;
    
    }
return head;


}

void print(node* &root)
{
    while (root!=NULL) {
        cout<<root->data;
        root= root->right;
    }
}

void findPreSuc(node* root, node* &pre, node* &suc, int key)
{
    // Base case
    if (root == NULL)  
    return ;
 
    // If key is present at root
    if (root->data == key)
    {
        // the maximum value in left subtree is predecessor
        if (root->left != NULL)
        {
            node* tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp ;
        }
 
        // the minimum value in right subtree is successor
        if (root->right != NULL)
        {
            node* tmp = root->right ;
            while (tmp->left)
                tmp = tmp->left ;
            suc = tmp ;
        }
        return ;
    }
 
    // If key is smaller than root's key, go to left subtree
    if (root->data > key)
    {
        suc = root ;
        findPreSuc(root->left, pre, suc, key) ;
    }
    else // go to right subtree
    {
        pre = root ;
        findPreSuc(root->right, pre, suc, key) ;
    }
}

int main(){    
    // int in[]={1,2,3,4,5,6,7,8};
    // int pre[]={5,3,1,2,4,6,8,7}; 
    //int post[]={3,4,1,5,2,0};
    // /int n=8;
//node* root=buildtreefrompre(in,pre,n);
// node* root2=buildtreefrompost(in,post,n);
 
    node* root=NULL;
    // node* root2=NULL;
    // node* head1=NULL;
    // node* head2=NULL;
    cout<<"enter data to create bst"<<endl;
    takeinput(root);
    // cout<<"enter data to create bst"<<endl;
    // takeinput(root2);
    // //inorder(root);
    // node* root=mergebst(root1,root2);

    //bst into sorted dll
    // convertintosorteddoublylinkl(root1,head1);
    // head1->left=NULL;
    // convertintosorteddoublylinkl(root2,head2);
    // head2->left=NULL;
 
    cout<<"printing the bst"<<endl;

    //mergedll

    // node* root=megre2linklist(head1,head2);

    // print(root);
      printtransversal(root);
//   int key=0; 
//     node* pree = NULL;
//     node* suc = NULL;
 
//     findPreSuc(root, pree, suc, key);
//     if (pree != NULL)
//       cout << "Predecessor is " << pree->data << endl;
//     else
//       cout << "No Predecessor";
 
//     if (suc != NULL)
//       cout << "Successor is " << suc->data;
//     else
//       cout << "No Successor";
//     return 0;

  
   // cout<<"minheight is :"<<minDepth(root);
    cout<<"inorder:"<<endl;
    inorder(root);

    cout<<"preorder:"<<endl;
    preorder(root);

    cout<<"postorder:"<<endl;
    postorder(root);

    return 0;
}