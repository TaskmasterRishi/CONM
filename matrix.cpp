#include<iostream>
using namespace std;

int main(){
    int a[3][3], b[3][3], c[3][3], d[3][3];
    int i,j,k;
    cout<<"Enter matrix a : ";
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cin>>a[i][j];
        }
    }
    cout<<"Enter matrix b : ";
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cin>>b[i][j];
        }
    }
    cout<<"Matrix addition"<<endl;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            c[i][j]=a[i][j]+b[i][j];
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"matrix multiplication : "<<endl;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
                d[i][j]=0;
            for(k=0;k<3;k++){
                d[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
