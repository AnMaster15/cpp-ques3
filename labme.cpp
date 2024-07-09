#include<iostream>
#include<queue>
using namespace std;




int main(){
    queue<int>q;
     cout<<"enter the number to be enter int he queeue"<<endl;
int n;
    cin>>n;

    q.push(3);
     q.push(4);
      q.push(5);
       q.push(6);
        q.push(7);
         q.push(8);

         for(int i=0;i<n;i++){
            cout<<q.front()<<endl;
            q.pop();
         }

         





    return 0;
}