#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int kth_largest(vector<int>&arr,int k  , int n){
    priority_queue<int , vector<int> , greater<int> >minheap;
    //step 1
    for(int i = 0;i<k;i++){
        minheap.push(arr[i]);
    }
    // step 2
    for(int i = k ; i<n; i++){
        if(arr[i]>minheap.top()){
            minheap.pop();
            minheap.push(arr[i]);
        }
    }

    return minheap.top();

}

int main(){
    int n ;
    cout<<"No of ele in array : ";
    cin>>n ;
    
    cout<<"input array ele : "<<" ";
    vector<int>arr(n);
    for(int i =0 ; i<n ;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"kth time sort : ";
    cin>>k;
    
    cout<<kth_largest(arr,k,n);

}
