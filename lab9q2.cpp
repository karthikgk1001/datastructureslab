#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    // Find the two largest strengths
    int max1 = *max_element(s.begin(), s.end());
    int max2 = -1;

    // Find the second largest element
    for (int i = 0; i < n; i++) {
        if (s[i] != max1) {
            max2 = max(max2, s[i]);
        }
    }

    
    if (max2 == -1) max2 = max1;

    
    for (int i = 0; i < n; i++) {
        if (s[i] == max1) {
            cout << s[i] - max2 << " ";
        } else {
            cout << s[i] - max1 << " ";
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
