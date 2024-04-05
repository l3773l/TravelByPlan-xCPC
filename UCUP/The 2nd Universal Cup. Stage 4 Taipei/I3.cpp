 #include <bits/stdc++.h>
#include <numeric>
 using namespace std;

// #define NDEBUG

 int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> arr(n);
    for (auto &i : arr) {
        cin >> i;
    }
    vector<long long> diff;
    adjacent_difference(arr.begin(), arr.end(), back_inserter(diff));
    // diff.pop_back();
    vector<long long> posNum, neNum;
    for (auto i : diff) {
        if (i < 0) {
            neNum.push_back(i);
        } else if (i > 0) {
            posNum.push_back(i);
        }
    }
    sort(posNum.begin(), posNum.end(), greater<long long>{});
    sort(neNum.begin(), neNum.end() );
    #ifndef NDEBUG
        for (auto i : posNum) {
            cout << i << ' ';
        }
        cout << endl;
        for (auto i : neNum) {
            cout << i << ' ' ;
        }
        cout << endl;
    #endif
    auto curN = neNum.begin();
    auto curPos = posNum.begin();
    int count = 0;
    while (curPos != posNum.end() && curN != neNum.end()) {
        ++count;
        auto remain = *curN + *curPos;
        if (remain == 0) {
            ++curN;
            ++curPos;
        } else if (remain > 0) {
            ++curN;
            *curPos = remain;
        } else {
            ++curPos;
            *curN = remain;
        }        
    }
    
    auto disP = distance(curPos, posNum.end());
    auto disN = distance(curN, neNum.end());
    #ifndef NDEBUG
        cout << count << endl;
        cout << disP << endl;
        cout << disN << endl;
    #endif
    cout << count + disP + disN << endl;
 }