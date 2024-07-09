#include<iostream>
using namespace std;

class stack{

    public:
    int *arr;
    int top;
    int size;

    stack s(int size ){

        arr=new int[size];
        top=-1;

    }

    void push(int element){
        if(size-top>1){
            top++;
            arr[top]=element;
        }
        else
        {
            cout<<"stack is overflow"<<endl;
        }
    }

    void pop(){
        if(top==-1){
            cout<<"stack is underflow"<<endl;
        }
        else{
            top--;
        }
    }

    int peek(){
        if(top==-1){
            cout<<"no value found"<<endl;
        }
        else{
            return arr[top];
        }
    }

    bool isempty(){
        if(top==-1){
            return true;
        }
        else{
        return false;}
    }

    bool isfull(){
        if(size-top>1){
            return true;
        }
        else{
            return false;
        }
    }





int peek(){




}
};

int main(){

    int arr;







    return 0;
}