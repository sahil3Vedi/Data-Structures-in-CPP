#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;//Number of String Inputs
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    int j;
    for (j=n-1;j>0;j--){
        cout<<arr[j]<<" ";
    }
    cout<<arr[j];
    return 0;
}
