#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long offX, offY;
    offX = offY = 0;
    
    int n;
    cin >> n;

    for (int i=0; i<n; ++i) {
        char d;
        int dis;
        cin >> d >> dis;
        switch (d)
        {
        case 'S':
            offY -= dis;
            break;
        case 'N':
            offY += dis;
            break;
        case 'E':
            offX += dis;
            break;
        case 'W':
            offX -= dis;
            break;
        default:
            break;
        }
    }
    if (offX == 0 || offY == 0) {
        cout << "1 ";
        if (offX > 0) {
            cout << "E\nZ " << offX << endl;
        } else if (offX < 0) {
            offX = -offX;
            cout << "W\nZ " << offX << endl;
        } else if (offY > 0) {
            cout << "N\nZ " << offX << endl;
        } else {
            offY = -offY;
            cout << "S\nZ " << offX << endl;
        }
    } else {
        cout << "3 ";
        if (offX > 0) {
            cout << "E\nZ";
        } else {
            cout << "W\nZ";
        }
        cout << ' ' << abs(offX) << endl;
        if (offX > 0) {
            if (offY > 0) {
                cout << "L" << endl;
            } else {
                cout << "R" << endl;
            }
        } else {
            if (offY > 0) {
                cout << "R" << endl;
            } else {
                cout << "L" << endl;
            }
        }
        cout << "Z " << abs(offY) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}