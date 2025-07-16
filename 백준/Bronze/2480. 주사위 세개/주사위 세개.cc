// boj 2480

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n[3];
    cin >> n[0] >> n[1] >> n[2];
    
    if ((n[0] == n[1]) && (n[1] == n[2])) cout << 10000 + n[0]*1000;
    else if ((n[0] == n[1]) || (n[0] == n[2])) cout << 1000 + n[0]*100;
    else if (n[1] == n[2]) cout << 1000 + n[1]*100;
    else cout << max({n[0], n[1], n[2]}) * 100;

    return 0;
}
