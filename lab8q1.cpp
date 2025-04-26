#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> towers(n);
        int total = 0;
        for (int i = 0; i < n; ++i) {
            cin >> towers[i];
            total += towers[i];
        }
        cout << total << endl;
    }
    return 0;
}
