#include<iostream>
using namespace std;

class circularqueue{
    public:

    int size;
    int front;
    int rear;
    int *arr;

    circularqueue(int value){
        this->size=value;
        arr=new int[size];
        front=-1;
        rear=-1;

    }

    void enqueue(int element){
        if((front==0 && rear==size-1) || (rear==(front-1)%size-1 )){
            cout<<"overflow"<<endl;
        }
        else if(front==-1){
            front=rear=0;
            
        }
        else if(rear== size -1 && front!=0){
            rear=0;
            
        }
        else{
            rear++;
        }
        arr[rear]=element;

        
    }

    void dequeue(){
        if(front==-1){
            cout<<"underflow"<<endl;
        }
        arr[front]=-1;
         if(front==rear){//single element
            front=rear=-1;
        }
        else if(front==size-1){
            front=0;
        }
        else{
            front++;
        }
    }

    int peek(){
        int ans;
       if(front==-1){
            cout<<"underflow"<<endl;
        }
        else{
             ans=arr[front];
             front++;
        }
        return ans;
    }

};

int main(){

    circularqueue q(5);

    q.enqueue(1);
    q.enqueue(5);
    q.peek();

   






    return 0;
}