#include<iostream>
#include<vector>
using namespace std;


int main(){
    int n , m ,k ;
    cin>>n >>m >>k ;

    vector<int>arr1(n );
    vector<int>arr2(m  );
    vector<int>arr3(k );

    for(int i = 0 ;i< n ; i++){
        cin>>arr1[i];
    }
    for(int i = 0 ;i< m ; i++){
        cin>>arr2[i];
    }
    for(int i = 0 ;i< k ; i++){
        cin>>arr3[i];
    }

    int target ;
    cout<<"target : ";
    cin>>target ;

    vector<vector<int>>ans;

    for ( int i =0;i<n ; i++){
        for(int j =0;j<m;j++){
            for(int p =0;p<k ; p++){
                if(arr1[i]+arr2[j]+arr3[p] ==target){
                    ans.push_back({arr1[i],arr2[j],arr3[p]});
                }
            }
        }
    }

    for(auto& r : ans){
        for(auto& h : r){
            cout<<h<<" ";
        }
    }cout<<endl;

    return 0;

}