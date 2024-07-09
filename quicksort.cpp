#include<iostream>
using namespace std;

int partition(int *arr,int s,int e){

    int p=arr[s];

    int count=0;

    for(int i=s+1;i<=e;i++){
        if(p>=arr[i]){
            count++;
        }
        
    }

    int pindex=s+count;

    swap(arr[pindex],arr[s]);


    int i=s;

    int j=e;

    while(i<pindex && j>pindex){
        while(arr[i]<p){
            i++;
        }
        while(arr[i]>p){
            j--;
        }

        if(i>pindex && j<pindex){
            swap(arr[i++],arr[j--]);
        }
    }

    return pindex;
   



}
void quicksort(int *arr,int s,int e){

    if(s>=e){
        return;
    }

    int p=partition(arr,s,e);

    quicksort(arr,s,p-1);

    quicksort(arr,p+1,e);

}

int main(){

    int arr[5]={2,45,7,8,23};

    int n=5;

    quicksort(arr,0,n-1);

    for(int i=0;i<n;i++){
    cout<<arr[i]<<endl;
}

    return 0;
}

// #include <iostream>
// using namespace std;

// int partition(int *arr, int s, int e) {
//     int p = arr[s];
//     int count = 0;

//     for (int i = s + 1; i <= e; i++) {
//         if (p >= arr[i]) {
//             count++;
//         }
//     }

//     int pindex = s + count;
//     swap(arr[pindex], arr[s]);

//     int i = s;
//     int j = e;

//     while (i < pindex && j > pindex) {
//         while (arr[i] <= p) {
//             i++;
//         }
//         while (arr[j] > p) {
//             j--;
//         }

//         if (i < pindex && j > pindex) {
//             swap(arr[i], arr[j]);
//             i++;
//             j--;
//         }
//     }

//     return pindex;
// }

// void quicksort(int *arr, int n) {
//     int s = 0;
//     int e = n - 1;

//     while (s < e) {
//         int p = partition(arr, s, e);

//         if (p - s < e - p) {
//             s = p + 1;
//         } else {
//             e = p - 1;
//         }
//     }
// }

// int main() {
//     int arr[5] = {2, 45, 7, 8, 23};
//     int n = 5;

//     quicksort(arr, n);

//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << endl;
//     }

//     return 0;
// }
