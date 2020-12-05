#include<vector>
#include<iostream>
#include <queue>
#include<algorithm>
#include <cstring>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int numn = maps.size();
    int numm = maps[0].size();
    int map[101][101];
    memset(map, 10000, sizeof(map));
    map[0][0] = 0;
    int x = 0;
    int y = 0;
    int x1, y1;
    queue<pair<int, int>> q;
    q.push(make_pair(0,0));
    int mapx[4] = {1, 0, -1, 0};//아래, 오른쪽, 위, 왼쪽
    int mapy[4] = {0, 1, 0, -1};
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            x1 = x + mapx[i];
            y1 = y + mapy[i];
            if(x1 <0 || x1 >= numn || y1 <0 || y1 >= numm){
                continue;
            }
            if(maps[x1][y1] == 0){
                continue;
            }
            if(map[x1][y1] > map[x][y] + 1){
                map[x1][y1] = map[x][y] + 1;
                q.push(make_pair(x1,y1));
            }
        }
    }
    
    answer = map[numn-1][numm-1] + 1;
    if(answer > 1000000){
        answer = -1;
    }
    return answer;
}
