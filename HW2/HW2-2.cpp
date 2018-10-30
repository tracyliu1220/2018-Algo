#include <bits/stdc++.h>
using namespace std;
#define MAX 10005

int dp[2][MAX] = {0};
int ans[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s1; cin >> s1;
	string s2(s1); reverse(s2.begin(), s2.end());
	int n = s1.size();
	
	for (int i = 1; i <= n; i ++) {
		memset(dp[i % 2], 0, sizeof(dp[i % 2]));
		for (int j = 1; j <= n; j ++) {
			dp[i % 2][j] = max(dp[!(i % 2)][j], dp[i % 2][j - 1]);
			if (s1[i - 1] == s2[j - 1])
				dp[i % 2][j] = max(dp[i % 2][j], dp[!(i % 2)][j - 1] + 1);
		}
		ans[i] = dp[i % 2][n + 1 - i];
	}

	for (int i = 1; i <= n; i ++)
		cout << ans[i] * 2 - 1 << ' ';
	cout << '\n';
}
