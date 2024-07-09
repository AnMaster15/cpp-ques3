#include<iostream>
using namespace std;

int main(){

    int arr[7]={10,1,74,8,2,11};

    int n=7;
    int i,j,key;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
     
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

 
// A util
    

    // for( i=1;i<n;i++){
    //     int temp=arr[i];
    //     int j=i-1;
    //    for( ;j>=0;j--){

    //     if(arr[j+1]>temp){
    //         arr[j+1]=arr[j];
    //     }
    //     else{
    //         break;
    //     }
    //     }
    //     arr[j+1]=temp;
    // }
    for(int k=0;k<n;k++){
        cout<<arr[k]<<endl;
    }

    return 0;
}