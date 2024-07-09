#include<iostream>
using namespace std;

class deque{

public:

int *arr;
int front;
int rear;
int size;

deque(int size){
    this->size=size;
    arr=new int[size];
    front=rear=-1;

}

void push_front(int element){
    if((front==0 && rear==size-1) || (rear==(front-1)%size-1 )){
            cout<<"overflow"<<endl;
        }
        else if(front==-1){
            front=rear=0;
           
        }
        else if(front== 0 && rear!=size-1){
         front=size-1;
           
        }
        else{
            front--;
        }
        arr[front]=element;


}

void push_rear(int element){
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

void pop_front(){
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
void pop_rear(){
     if(front==-1){
            cout<<"underflow"<<endl;
        }
        arr[rear]=-1;
         if(front==rear){//single element
            front=rear=-1;
        }
        else if(rear==0){
            rear=size-1;
        }
        else{
            rear--;
        }
}
int getfront(){
    if(front==-1){
            cout<<"underflow"<<endl;
        }
        else return arr[front];

}


};

int main(){

    deque d(5);

    d.push_rear(34);
    d.push_rear(74);
    d.push_front(7);
 d.push_front(26);
  d.push_front(50);
  d.getfront();
    return 0;
}