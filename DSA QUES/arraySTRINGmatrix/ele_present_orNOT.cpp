#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int n , m ;
    cin>>n>>m;

    vector<vector<int>>v(n,vector<int>(m));
    for(int i =0 ; i<n ;i++){
        for(int j = 0 ; j<m ; j++){
            cin>>v[i][j];
        }
    }
    int k ;
    cin>>k;
    for(auto a:v){
        if(find(a.begin(),a.end(),k)!=a.end()){
            cout<<1<<endl;
        }

    }

    
    return 0 ;
}