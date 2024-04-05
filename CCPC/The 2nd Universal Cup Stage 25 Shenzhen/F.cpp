#include <bits/stdc++.h>

using namespace std;
// #define MULTICASE

bool isConnected(vector<set<int>> &g) {
    vector<bool> vis(g.size(), false);
    queue<int> nxtPoint;
    nxtPoint.push(1);
    while (!nxtPoint.empty()) {
        auto curPoint = nxtPoint.front();
        nxtPoint.pop();
        if (!vis[curPoint]) {
            vis[curPoint] = true;
            for (auto i : g[curPoint]) {
                if (!vis[i]) {
                    nxtPoint.push(i);
                }
            }
        }
    }
    return none_of(vis.begin()+1, vis.end(), [](int i) {return i == false;});
}

void solve() {
    int n;
    cin >> n;
    vector<set<int>> graph(n+1);

    vector<int> degree(n+1, 0);
    for (int i=0; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
        degree[a]++;
        degree[b]++;
    }

    if (!isConnected(graph)) {
        cout << 0;
        exit(0);
    }

    auto baseDegree = degree;
    queue<int> leaf;
    vector<bool> hasRemoved(n+1, false);
    for (int i=1; i<=n; ++i) {
        if (degree[i] == 1) {
            leaf.push(i);
        }
    
    }

    while (!leaf.empty()) {
        auto curPos = leaf.front();
        leaf.pop();
        hasRemoved[curPos] = true;
        for (auto child : graph[curPos]) {
            if (hasRemoved[child]) {
                continue;
            }
            graph[child].erase(curPos);
            --degree[child];
            if (degree[child] <= 1) {
                leaf.push(child);
            }
        }
    }
    vector<int> cir;
    for (int i=1; i<=n; ++i) {
        if (!hasRemoved[i]) {
            auto cur = i;
            auto prv = 0;
            do {
                // cout << cur << endl;
                cir.push_back(cur);
                
                for (auto i : graph[cur]) {
                    if (i != prv) {
                        prv = cur;
                        cur = i;
                        break;
                    }
                }
                
            } while (cur != i);
            cir.push_back(i);
            break;
        }
    }

    int d3 = 0;
    int d5 = 0;
    for (int i=1; i<=n; ++i) {
        if (baseDegree[i] <= 3) {
            ++d3;
        } else if (baseDegree[i] == 5) {
            ++d5;
        } else if (baseDegree[i] > 5) {
            cout << 0;
            exit(0);
        }
    }

    long long ans = 0;
    // clog << d3 << ' ' << d5 << endl;
    for (int i=0; i<cir.size()-1; ++i) {
        auto from = cir[i];
        auto to = cir[i+1];
        // cout << from << ' ' << to << endl;
        auto d3c = d3;
        auto d5c = d5;
        
        if (baseDegree[from] == 5) {
            d5c--;
        } else if (baseDegree[from] == 4) {
            d3c++;
        }
        if (baseDegree[to] == 5) {
            d5c--;
        } else if (baseDegree[to] == 4) {
            d3c++;
        }
        // clog << d3c << ' ' << d5c << endl;
        if (d5c == 0) {
            ans += d3c;
        }
        
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    #ifdef MULTICASE
        int n;
        cin >> n;
        for (int i=0; i<n; ++i)
    #endif
    {
        solve();
        // cout << '\n';
    }
    return 0;
}