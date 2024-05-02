#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string str;
	cin >> str;
	
	size_t pos =0;
	while ((pos = str.find("cjb", pos) )!= string::npos) {
		auto endIter = str.begin() + pos + 3;
		str.insert(endIter, ',');
		pos += 3;
	}
	cout << str << endl;
}
