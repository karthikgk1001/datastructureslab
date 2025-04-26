#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int k, q;
    cin >> k >> q;
    vector<int> a(k);
    
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }

    while (q--) {
        int n;
        cin >> n;

        int winners = n; // Assume initially all `n` players remain

        // Find the first index where `a[i]` is greater than `n`
        for (int i = 0; i < k; i++) {
            if (a[i] > n) break;  
            winners--; 
        }

        cout << winners << " ";
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
