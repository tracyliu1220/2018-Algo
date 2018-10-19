#include <bits/stdc++.h>
using namespace std;

map<char, int> m;

int main() {
	string s;
	cin >> s;

	int ans = 0;
	
	for (int i = 0; i < s.size(); i ++) {
		m[s[i]] ++;
		ans = max(ans, m[s[i]]);
	}

	cout << ans << '\n';
}
