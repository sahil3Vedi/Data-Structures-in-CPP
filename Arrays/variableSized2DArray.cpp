#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;// number of arrays
    int q;// number of queries
    cin>>n;
    cin>>q;
    int** a;//declaring a pointer of pointers
    a = new int*[n];// a is an array of pointers that points towards n arrays having integers
    for (int i=0;i<n;i++){
        int k;
        cin>>k;
        a[i] = new int[k];// ith index of a points towards an array of k indices
        for (int j=0;j<k;j++){
            cin>>a[i][j];// practically a 2D array at this point
        }
    }
    for (int x=0;x<q;x++){
        int w,h;
        cin>>w;
        cin>>h;
        cout<<a[w][h]<<endl;// fetches like a 2D array
    }
    return 0;
}
