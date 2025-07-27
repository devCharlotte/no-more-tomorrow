#include <vector>
using namespace std;

int solution(vector<vector<int>> maps) {
    int n = maps.size();          // 맵 세로 길이
    int m = maps[0].size();       // 맵 가로 길이
    int total = n * m;            // 총 노드 개수 
    int answer = -1;              // 도달할 수 있는 최단 거리 (-1은 도달 불가)

    bool visited[10001] = {false}; // 방문 여부 
    
    // 인접 행렬 (graph[a][b] == 1 a-b 연결)
    vector<vector<int>> graph(total, vector<int>(total, 0)); 

    int dx[4] = {1, -1, 0, 0};    // x축 이동 (동, 서, 남, 북)
    int dy[4] = {0, 0, 1, -1};    // y축 이동 (동, 서, 남, 북)

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (maps[y][x] == 1) { // 이동 가능한 칸만
                int cur = y * m + x; // 현재 칸의 번호 
                for (int i = 0; i < 4; i++) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if (ny >= 0 && ny < n && nx >= 0 && nx < m && maps[ny][nx] == 1) {
                        int neighbor = ny * m + nx; // 인접 칸의 노드 번호 
                        graph[cur][neighbor] = 1;   // 연결 표시
                    }
                }
            }
        }
    }

    // BFS
    vector<vector<int>> q;      // 큐 역할 (노드 번호, 현재까지 이동 거리)
    q.push_back({0, 1});        // 시작 노드(0), 시작 칸 수=1
    visited[0] = true;          // 시작 노드 방문 O

    int front = 0;              // 큐 front
    while (front < q.size()) {
        int node = q[front][0]; // 현재 탐색 중인 노드
        int distance = q[front][1]; // 시작점에서 현재 노드까지의 거리
        front++;

        if (node == (n - 1) * m + (m - 1)) { // 목표 노드 도착
            answer = distance; 
            break;
        }

        // 인접한 노드 탐색
        for (int next = 0; next < total; next++) {
            if (graph[node][next] == 1 && !visited[next]) {
                visited[next] = true;            // 방문 처리
                q.push_back({next, distance + 1});   // 큐에 추가 (거리 +1)
            }
        }
    }

    return answer;
}
