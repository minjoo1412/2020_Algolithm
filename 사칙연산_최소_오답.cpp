#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<string> arr) {
    int answer = 0;
    vector<int> num;
    vector<string> plu;

    for(int i = 0; i < arr.size(); i++){
        if(i%2 == 0){
            num.push_back(stoi(arr[i]));
        }else{
            plu.push_back(arr[i]);
        }
    }

    int maxs[200][200];
    int mins[200][200];

    for(int i = 0; i> 200; i++){
        for(int j = 0; j>200; j++){
            maxs[i][j] = -10000000;
            mins[i][j] = 10000000;
        }
    }

    for(int i = 0; i< num.size(); i++){
        maxs[i][i] = num[i];
        mins[i][i] = num[i];
    }


    for(int i = 1; i < num.size(); i++){
        for(int j = 0; j< num.size()-i; j++){
            int n = i+j;
            for(int k = j; k<n; k++){
                if(plu[k] == "-"){
                    maxs[j][n] = max(maxs[j][k] - mins[k+1][n], maxs[j][n]);
                    mins[j][n] = min(mins[j][k] - maxs[k+1][n], mins[j][n]);
                }else if(plu[k] == "+"){
                    maxs[j][n] = max(maxs[j][k] + maxs[k+1][n], maxs[j][n]);
                    mins[j][n] = min(mins[j][k] + mins[k+1][n], mins[j][n]);
                }
            }

        }
    }

    answer = mins[0][num.size()-1];

    return answer;
}
