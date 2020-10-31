#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int maxs[102][102];
int mins[102][102];

int solution(vector<string> arr)
{
    int answer = 1;
    
    vector<int> num;
    vector<string> plu;
    for(int i = 0; i < arr.size(); i++){
        if(i%2 == 0){
            num.push_back(stoi(arr[i]));
        }else{
            plu.push_back(arr[i]);
        }
    }
    
    for(int i = 0; i < 102; i++){
        for(int j = 0; j < 102; j++){
            maxs[i][j] = -1000000;
            mins[i][j] = 1000000;
        }
    }
    
    for(int i = 0; i < num.size(); i++){
        maxs[i][i] = num[i];
        mins[i][i] = num[i];
    }
    
    for (int i = 1; i < num.size(); i++) {
		for (int j = 0; j < num.size() - i; j++) {
			int n = i + j;
			for (int k = j; k < n; k++) {
				if (plu[k] == "-") {
					maxs[j][n] = max(maxs[j][k] - mins[k + 1][n], maxs[j][n]);
					mins[j][n] = min(mins[j][k] - maxs[k + 1][n], mins[j][n]);
				}else if (plu[k] == "+") {
					maxs[j][n] = max(maxs[j][k] + maxs[k + 1][n], maxs[j][n]);
					mins[j][n] = min(mins[j][k] + mins[k + 1][n], mins[j][n]);
				}
			}
		}

	}
	answer = maxs[0][num.size()-1];
    
    return answer;
}
