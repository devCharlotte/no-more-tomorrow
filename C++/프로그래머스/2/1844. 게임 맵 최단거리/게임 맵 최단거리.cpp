#include <vector>
using namespace std;

int solution(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();

    int dx[4] = {1, -1, 0, 0};    // 동서남북
    int dy[4] = {0, 0, 1, -1};    

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<int> qy;  // y 큐
    vector<int> qx;  // x 큐
    vector<int> qd;  // 거리 큐

    qy.push_back(0);
    qx.push_back(0);
    qd.push_back(1);
    visited[0][0] = true;

    int front = 0;
    while (front < qy.size()) {
        int y = qy[front];
        int x = qx[front];
        int dist = qd[front];
        front++;

        // 목표 지점 도착
        if (y == n - 1 && x == m - 1) return dist;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];

            if (ny >= 0 && ny < n && nx >= 0 && nx < m &&
                maps[ny][nx] == 1 && !visited[ny][nx]) {
                visited[ny][nx] = true;
                qy.push_back(ny);
                qx.push_back(nx);
                qd.push_back(dist + 1);
            }
        }
    }

    return -1; // 도달 불가
}