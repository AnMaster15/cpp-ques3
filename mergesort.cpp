#include<iostream>
using namespace std;

void merge(int *arr,int s,int e){


int mid =(s+e)/2;
    int len1=mid-s+1;
    int len2=e-mid;

    int *arr1=new int[len1];
    int *arr2=new int[len2];

    int k=s;

    for(int i=0;i<len1;i++){

        arr1[i]=arr[k];
        k++;

    }
     k=mid+1;
     for(int i=0;i<len2;i++){

        arr2[i]=arr[k];
        k++;
       
    }

    int index1=0;
    int index2=0;

    int key=s;

    while(index1<len1 && index2 < len2){
        if(arr1[index1]<arr2[index2]){
            arr[key]=arr1[index1];
            key++;
            index1++;
        }
        else{
            arr[key]=arr2[index2];
            key++;
            index2++;
        }
    }

    while(index1<len1 ){
       
            arr[key]=arr1[index1];
            key++;
            index1++;
        }


        while( index2 < len2){
       
            arr[key]=arr2[index2];
            key++;
            index2++;
        }
}

void mergesort(int *arr,int s,int e){

    if(s>=e){
        return ;
    }
    int mid=(s+e)/2;


    mergesort(arr,s,mid);

    mergesort(arr,mid+1,e);

    merge(arr,s,e);




}

int main(){

    int arr[7]={5,78,34,12,8,90,1};

    int n=7;

    mergesort(arr,0,n-1);

for(int i=0;i<n;i++){
    cout<<arr[i]<<endl;
}

    return 0;
}

// #include <iostream>
// using namespace std;

// void merge(int *arr, int s, int mid, int e) {
//     int len1 = mid - s + 1;
//     int len2 = e - mid;

//     int *arr1 = new int[len1];
//     int *arr2 = new int[len2];

//     for (int i = 0; i < len1; i++)
//         arr1[i] = arr[s + i];

//     for (int i = 0; i < len2; i++)
//         arr2[i] = arr[mid + 1 + i];

//     int index1 = 0;
//     int index2 = 0;
//     int key = s;

//     while (index1 < len1 && index2 < len2) {
//         if (arr1[index1] < arr2[index2]) {
//             arr[key] = arr1[index1];
//             key++;
//             index1++;
//         } else {
//             arr[key] = arr2[index2];
//             key++;
//             index2++;
//         }
//     }

//     while (index1 < len1) {
//         arr[key] = arr1[index1];
//         key++;
//         index1++;
//     }

//     while (index2 < len2) {
//         arr[key] = arr2[index2];
//         key++;
//         index2++;
//     }

   
// }

// void mergesort(int *arr, int n) {
//     for (int i = 1;i <= n - 1; i = 2 * i) {
//         for (int j = 0; j < n - 1;j += 2 * i) {
//             int mid = min(j + i - 1, n - 1);
//             int right_end = min(j + 2 * i - 1, n - 1);
//             merge(arr, j, mid, right_end);
//         }
//     }
// }

// int main() {
//     int arr[7] = {5, 78, 34, 12, 8, 90, 1};
//     int n = 7;

//     mergesort(arr, n);

//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }

//     return 0;
// }
