#include <iostream>
using namespace std;

int ackermann_recursive(int m, int n) {
    if (m == 0) return n + 1;
    else if (n == 0) return ackermann_recursive(m - 1, 1);
    else return ackermann_recursive(m - 1, ackermann_recursive(m, n - 1));
}

int main() {
    int m = 2, n = 3;
    cout << "Recursive Ackermann(" << m << ", " << n << ") = " << ackermann_recursive(m, n) << endl;
    return 0;
}
