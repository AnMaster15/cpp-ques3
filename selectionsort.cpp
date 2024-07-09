#include<iostream>
using namespace std;

int main(){

    int min=0;

    int arr[5]={2,35,12,98,55};
    int n=5;

    for(int i=1;i<n;i++){
        min=arr[i];

        for(int j=i-1;j<n;j++){
            if(arr[j]>arr[i]){
                swap(arr[j],arr[i]);
            }
        }

    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }

    

    return 0;
}