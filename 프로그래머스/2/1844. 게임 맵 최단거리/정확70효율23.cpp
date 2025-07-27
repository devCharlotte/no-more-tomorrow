#include <vector>
using namespace std;

int solution(vector<vector<int>> maps) {
    int n = maps.size();          // 맵 세로
    int m = maps[0].size();       // 맵 가로

    vector<vector<int>> q;        // BFS 큐  y좌표, x좌표, 현재까지 이동 거리

    // 동서남북 
    int dx[4] = {1, -1, 0, 0};    
    int dy[4] = {0, 0, 1, -1};    
    
    vector<vector<bool>> visited(n, vector<bool>(m, false)); // 방문 여부
    
    q.push_back({0, 0, 1});       // 시작점 (0,0), 거리 +1
    visited[0][0] = true;         // 시작점 방문했음!

    int front = 0;                // 큐 front (pop 대신 인덱스 증가)
    while (front < q.size()) {
        int x = q[front][1];      // 탐색 중인 x
        int y = q[front][0];      // 탐색 중인 y
        int dist = q[front][2];   // 현재까지 거리 누적합
        front++;

        // 목표 지점이면 거리 리턴
        if (y == n - 1 && x == m - 1) return dist;

        // 상하좌우 탐색
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            // 맵 범위 내부 + r갈 수 있는 1칸 + 아직 방문 x 
            if (ny >= 0 && ny < n && nx >= 0 && nx < m && maps[ny][nx] == 1 && !visited[ny][nx]) {
                visited[ny][nx] = true;          // 방문 
                q.push_back({ny, nx, dist + 1}); // 큐에 다음 칸과 거리 추가
            }
        }
    }

    return -1; // 큐를 다 돌았는데 못 갔으면 -1
}
