#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int ksmallest(vector<int>&arr,int k  , int n){
    priority_queue<int>maxheap;
    //step 1
    for(int i = 0;i<k;i++){
        maxheap.push(arr[i]);
    }
    // step 2
    for(int i = k ; i<n; i++){
        if(arr[i]<maxheap.top()){
            maxheap.pop();
            maxheap.push(arr[i]);
        }
    }

    return maxheap.top();

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
    
    cout<<ksmallest(arr,k,n);

}
