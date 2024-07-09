#include<iostream>
#include<queue>
using namespace std;

queue<int>q;


int main(){

    q.push(3);
     q.push(4);
      q.push(5);
       q.push(6);
        q.push(7);
         q.push(8);

         for(int i=0;i<6;i++){
            cout<<q.front()<<endl;
            q.pop();
         }



    return 0;
}