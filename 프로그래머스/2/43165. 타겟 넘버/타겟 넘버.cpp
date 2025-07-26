#include <string>
#include <vector>

using namespace std;

int cnt = 0; // 방법의 수 
bool arr[21]; // 

void dfs(const vector<int>& input, int target, int depth, int sum) {
    // input 숫자 배열
    // target 만들어야 하는 값
    // depth 배열에서 현재 탐색 중인 인덱스
    // sum 지금까지 계산의 누적합
    
    if (depth == input.size()) { // 깊이 = 숫자 개수 : 모든 숫자 다 사용한 경우
        if (sum == target) cnt++; // 계산 합 = 목표 숫자 : 방법 개수 +1
        return;
    }

    if (arr[depth]) { // arr 배열 bool 형식 - 항상 참인 경우
        dfs(input, target, depth + 1, sum + input[depth]); // 현재 탐색 중인 인덱스의 수를 더하거나 
        dfs(input, target, depth + 1, sum - input[depth]);// 현재 탐색 중인 인덱스의 수를 빼거나
    }
}

int solution(vector<int> numbers, int target) {
    // numbers = input
    cnt = 0;
    int n = numbers.size();

    for (int i = 0; i < n; i++) arr[i] = true; // 모든 값이 다음 값으로 이동 가능

    dfs(numbers, target, 0, 0); // 0번 인덱스부터 시작. 아무 것도 선택 안 했으니까 false
    return cnt;
}
