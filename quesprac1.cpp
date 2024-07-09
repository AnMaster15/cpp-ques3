#include<iostream>
using namespace std;

int main(){
    int arr[100];
    int n=6;

    for(int i=0;i<6;i++){
        cout<<"enter the value of arrray"<<endl;
        cin>>arr[i];

    }
    int sum=0;
    for(int i=0;i<6;i++){
        cout<<"values before ans"<<endl;
        
        cout<<arr[i]<<" ";
        sum=sum+arr[i];

    }
    int mean=(sum)/6;


// int indexToDelete = 2; // Index of the element to delete

for (int i = mean; i < n ; i++) {
    if(arr[i]>mean){
    arr[i] = arr[i + 1];} 
}

n--; 

    for(int i=0;i<6;i++){
        // if(arr[i]<=mean){
            // cout<<"answer"<<endl;
            cout<<arr[i]<<" "<<endl;

        }

        
    // }


    return 0;
}