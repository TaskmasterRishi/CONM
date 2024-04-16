#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int main(){
    int a[]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(a[0]);
    sort(a,a+n);
    cout<<"Permutations are : "<<endl;
    do{
            for(int i=0;i<n;i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
    }while(next_permutation(a,a+n));
    return 0;
}
