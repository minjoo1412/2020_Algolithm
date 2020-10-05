#include <string>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

int maxim_cross(int front, int mid, int back, vector<int> &param0){
    int left_sum = -200;
    int right_sum = -200;
    int sum = 0;
    for(int i = mid; i >= front; i-- ){
        sum = sum + param0[i];
        if(sum > left_sum){
            left_sum = sum;
        }
    }
    sum = 0;
    for(int i = mid+1; i <= back; i++ ){
        sum = sum + param0[i];
        if(sum > right_sum){
            right_sum = sum;
        }
    }
    return left_sum + right_sum;
    
}

int maxim(int front, int back, vector<int> &param0){
    int mid;
    int left_sum;
    int right_sum;
    int cross_sum;
    if(front == back){
        return param0[front];
    }else{
        mid = (front + back) / 2;
        left_sum = maxim(front, mid, param0);
        right_sum = maxim(mid+1, back, param0);
        cross_sum = maxim_cross(front, mid, back, param0);
        if(left_sum >= right_sum && left_sum >= cross_sum){
            return left_sum;
        }else if(right_sum >= left_sum && right_sum >= cross_sum ){
            return right_sum;
        }else{
            return cross_sum;
        }
    }
}

int solution(vector<int> param0) {
    int answer = 0;
    
    
    answer = maxim(0, param0.size() -1, param0);
    cout << answer;
    return answer;
}
