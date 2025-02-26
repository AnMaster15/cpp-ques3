#include<iostream>
#include<queue>
using namespace std;

class heap
{

public:

int arr[100];
int size=0;

    heap(){
        arr[0]=-1;
        size=0;
    }



void insert(int val){
    size=size+1;
    int index =size;
    arr[index]=val;

    while(index>1){
        int parent =index/2;
        if(arr[parent]<arr[index]){
            swap(arr[parent],arr[index]);
            index=parent;
        }
        else{
            return;
        }
    }

    
}
void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }



void deletefromheap(){
if(size==0){
    cout<<"nothing to delete"<<endl;
    return;
}

arr[1]=arr[size];
size--;

//take root node to its correct position

int i=1;
while(i<size){
    int leftindex=2*i;
    int rightindex=2*i+1;

    if(leftindex<size && arr[i]<arr[leftindex]){
        swap(arr[i],arr[leftindex]);
        i=leftindex;
    }
    else if(rightindex<size && arr[i]<arr[rightindex]){
        swap(arr[i],arr[rightindex]);
        i=rightindex;
    }
    else{
        return;
    }

}

    }

};

void heapify(int arr[],int n,int i){

    int largest=i;
    int left=2*i;
    int right=2*i+1;

    if(left<=n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<=n && arr[largest]<arr[right]){
        largest=right;
    }

    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

void heapsort(int arr[],int n){

    int size=n;

    while(size>1){

    swap(arr[size],arr[1]);
    size--;

    heapify(arr,size,1);
    }
}




int main(){

    heap h;
//     h.insert(50);
//     h.insert(55);
//     h.insert(53);
//     h.insert(52);
//     h.insert(54);
// // h.deletefromheap();
//     h.print();
//heap creation
    int arr[11]={-1,100, 50, 150, 200, 30, 10, 90, 80, 210, 130 };
int n=11;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }

    cout<<"printing the array now"<<endl;

    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
//heap sort

heapsort(arr,n);

for(int i=0;i<=n;i++){
        cout<<arr[i]<<" "<<endl;
    }




    cout<<"using prirority queue"<<endl;
//max heap
    // priority_queue<int>pq;

    // pq.push(4);
    // pq.push(2);
    // pq.push(5);
    // pq.push(3);

//     cout<<"element at top"<<pq.top();
//     pq.pop();
//     cout<<"element at top"<<pq.top();
//     cout<<"size is "<<pq.size();

// //min heap

priority_queue<int,vector<int>,greater<int>>minheap;

minheap.push(4);
     minheap.push(2);
    minheap.push(5);
     minheap.push(3);
      cout<<"element at top"<<minheap.top();
    minheap.pop();
    cout<<"element at top"<<minheap.top();
    cout<<"size is "<<minheap.size();



    return 0;
}