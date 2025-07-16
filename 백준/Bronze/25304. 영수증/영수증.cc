// boj 25304

#include <iostream>
using namespace std;

int main() {

    int i1, i2, a, b;
    cin >> i1;
    cin >> i2;
    for (int i = 0; i < i2; i++) {
        cin >> a >> b;
        i1 -= a * b;
    }

    if (i1 == 0) cout << "Yes";
    else cout << "No";

    return 0;
}