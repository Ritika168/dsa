#include <iostream>
using namespace std;
int sparsetoarray(int arr[][10],int row,int column);
int main() {
    int matrix[10][10],n,m, zero=0,nonzero=0;
    cout<<"enter no. of rows and columns\n";
    cin>>n>>m;
    cout<<"enter elements of matrix\n";
    for(int i=0;i<n;i++)
    {for(int j=0;j<m;j++)
    cin>>matrix[i][j];}
    cout<<"matrix is\n";
    for(int i=0;i<n;i++)
    {for(int j=0;j<m;j++)
    {
    cout<<matrix[i][j]<<" ";}
    cout<<endl;
    }
    for(int i=0;i<n;i++)
    {for(int j=0;j<m;j++)
    if(matrix[i][j]==0){
        zero++;
    }}
    
    if (zero>((n*m)*3)/4)
    {cout<<"it is a sparse matrix ";
    cout<<endl;
    cout<<"sparse to array is "<<endl;
    
        sparsetoarray(matrix,n,m);
    }
    else {cout<<"it is not a sparse matrix";}

    return 0;
}
int sparsetoarray(int arr[][10],int row,int column){
    int count;
    for(int i=0;i<row;i++)
    {for(int j=0;j<column;j++)
    if (arr[i][j]!=0)
    count++;}
    cout<<row<<" "<<column<<" "<<count<<endl;
    for(int i=0;i<row;i++)
    {for(int j=0;j<column;j++)
     if (arr[i][j]!=0)
    cout<<i+1<<" "<<j+1 <<" "<<arr[i][j]<<endl;}
    return 0;
}