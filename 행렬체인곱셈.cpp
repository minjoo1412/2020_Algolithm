#include <vector>
#include <climits>
#include <iostream>
#include <cmath>
#include <typeinfo>

using namespace std;

int main(void) {
    int n;
    vector<int> v;

    cin >>  n;
    for (int i=0; i<n+1; i++){
        int d;
        cin >> d;
        v.push_back(d);
    }
    
    int num = v.size()-1;
    
    long long** table = new long long*[num*2];
    for(int i = 0; i < num*2; i++){
        table[i] = new long long[num*2];
    }
    long long mini;
    
    for(int l = 0; l < num; l++){
        for(int i = 1; i <= num-l; i++){
            int j = i+l;
            if(i == j){
                table[i][j] = 0;
                continue;
            }
            table[i][j] = 10000000000000;
            
            for(int k = i; k<=j-1; k++){
                mini = table[i][k] + table[k+1][j] + v[i-1]*v[k]*v[j];
                table[i][j] = min(table[i][j], mini);
            }
        }
    }
    
    cout << table[1][num];
    
    
    // solve here and print the result using cout 
    return 0;
}
