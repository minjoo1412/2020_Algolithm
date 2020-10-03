#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <climits>
using namespace std;
static vector<pair<int, string>> x;

void mergesort(vector<pair<int, string>>& v, int p, int r){
    if(p<r){
        int mid = (p+r)/2;
        mergesort(v,p,mid);
        mergesort(v,mid+1,r);

        int a1 = p;
        int a2 = mid + 1;
        int c = p;
        int count = 0;
        for(int i = p; i <= r; i++){
            if(v[a1].first < v[a2].first){
                x[c++] = v[a2++];
            }else{
                x[c++] = v[a1++];
            }
            if(a1 > mid || a2 > r){break;}
        }
        
        while(a1 <= mid){
            x[c++] = v[a1++];
        }
        
        while(a2 <= r){
            x[c++] = v[a2++];
        }
        
        v.assign(x.begin(),x.end());
        
    }
};

int main(void) {
    int n;
    vector<pair<int, string> > v;

    cin >> n;

    for (int i=0; i<n; i++){
        int d;
        string s;
        cin >> d >> s;
        v.push_back(pair<int,string>(d,s));
    }

    x.assign(v.begin(),v.end());   
    
    // merge sort
    mergesort(v, 0, v.size()-1);

    for (int i=0; i<n; i++){
        cout << v[i].first << ' ' << v[i].second << endl;
    }

    return 0;
}
