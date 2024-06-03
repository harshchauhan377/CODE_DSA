#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print(vector<vector<int>>&matrix){
    int n = matrix[0].size();
    int m = matrix.size();
    int top = 0 , bottom = m-1 , left = 0 , right = n-1;

    while(top<=bottom && left <=right){
        for(int i = top ; i<=bottom ; i++){
            cout<<matrix[i][left]<<";";
        }
        left++;
        for(int i = left ; i<=right ; i++){
            cout<<matrix[bottom][i]<<";";
        }
        bottom--;
        if(top<=bottom){
            for(int i = bottom ; i>=top ; i--){
            cout<<matrix[i][right]<<";";
            }
            right--;
        }
        if(left<=right){
            for(int i = right ; i>=left ; i--){
            cout<<matrix[top][i]<<";";
            }
            top++;
        }
    }
    cout<<"END"<<endl;

}

int main(){
    int n , m ;
    cin>>n >>m ;
    vector<vector<int>>matrix(n,vector<int>(m));
    for(int i =0 ;i<n ;i++){
        for(int j =0 ; j<m ;j ++){
            cin>>matrix[i][j];
        }
    }
    print(matrix);
    return 0 ;
    

}