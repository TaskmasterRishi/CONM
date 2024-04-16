#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

int main(){
    string num;
    vector<int> even,odd;
    int n;
    int i=0;
    ifstream inF("input.txt");
    ofstream outF("output.txt");
    while(inF>>n){
        if(n%2==0){
            even.push_back(n);
        }
        else{
            odd.push_back(n);
        }
    }
    outF<<"Even numbers : "<<endl;
    for(i=0;i<even.size();i++){
        outF<<even[i]<<endl;
    }
    outF<<"Odd numbers : "<<endl;
    for(i=0;i<odd.size();i++){
        outF<<odd[i]<<endl;
    }
    inF.close();
    outF.close();
    return 0;
}
