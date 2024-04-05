#include <bits/stdc++.h>

using namespace std;
// #define MULTICASE

const map<char, int> level{{'M', 4}, {'C', 3}, {'X', 2}, {'I', 1}};
const map<int, char> rLevel{{4, 'M'}, {3, 'C'}, {2, 'X'}, {1, 'I'}};
struct matcher
{
    int curLevel = 0;
    int process = 0; // M 1 MM 2 MMM 3 MC 4 MCM 5
    string cache{};
    void match(char ch, vector<string> &substrs)
    {
        if (level.find(ch) != level.end())
        {
            if (process == 0)
            {
                cache.push_back(ch);
                process = 1;
                curLevel = level.at(ch);
            }
            else if (process < 4 && curLevel == level.at(ch))
            {
                cache.push_back(ch);
                ++process;
            }
            else if (process == 1 && curLevel != 1 && curLevel - 1 == level.at(ch))
            {
                cache.push_back(ch);
                process = 4;
            }
            else if (process == 4 && curLevel == level.at(ch))
            {
                cache.push_back(ch);
                process = 5;
            }
            else
            {
                finish(substrs);
                curLevel = level.at(ch);
                cache.push_back(ch);
            }
        } else {
            if (!cache.empty()) {
                finish(substrs);
            }
            substrs.push_back({ch});
            process = 0;
        }
        if (process == 3 || process == 5)
        {
            substrs.push_back(std::move(cache));
            process = 0;
        }
        return;
    }

    void finish(vector<string> &subStr)
    {
        if (process == 0) {
            return ;
        }
        if (process < 4 || process == 5)
        {
            subStr.push_back(std::move(cache));
        }
        else if (process == 4)
        {
            subStr.push_back({cache.front()});
            subStr.push_back({cache.back()});
        }
        process = 0;
    }
};

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<string> subStrs;
    matcher m;
    for (auto i : s)
    {
        m.match(i, subStrs);
    }
    m.finish(subStrs);
    cout << subStrs.size() << endl;
    for (auto &i : subStrs)
    {
        cout << i << endl;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

#ifdef MULTICASE
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
#endif
    {
        solve();
        // cout << '\n';
    }
    return 0;
}