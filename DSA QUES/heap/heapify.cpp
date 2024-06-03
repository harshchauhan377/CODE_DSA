#include<iostream>
#include<vector>
using namespace std;

 void heapify(vector<int>&arr , int n , int i  ){
    int largest = i ;
    int left = 2 * i +1;
    int right = 2 * i + 2;

    if(left < n && arr[left]> arr[largest]){
        largest = left ;
    }
    if(right < n && arr[right]> arr[largest]){
        largest = right ;
    }

    if(largest != i){
        swap(arr[i],arr[largest]);
        heapify(arr, n , largest);
    }

}

void print(vector<int>&arr ,int n ) {
    for(int i =0 ;i<n ;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n ;
    cout<<"array Size :";
    cin>>n;

    vector<int>arr(n);
    for(int i =0; i<n ;i++){
        cin>>arr[i];
    }

    for(int i =(n/2)-1 ; i>=0 ; i--){
        heapify(arr, n , i);
    }
    print(arr, n);

}