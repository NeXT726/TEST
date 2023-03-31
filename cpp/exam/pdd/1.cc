#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> memo;

int dp(vector<vector<int>>& path, int pos, int state) {
	if (pos == path.size()) {
		return 0;
	}

	if (memo[pos][state] == -1) {
		if (path[pos][0] == 0) {
			memo[pos][state] =
			    max(dp(path, pos + 1, state), dp(path, pos + 1, path[pos][1]));
		} else if (path[pos][0] == 1) {
			memo[pos][state] = dp(path, pos + 1, state);
			if (state == path[pos][1]) {
				memo[pos][state] =
				    max(memo[pos][state], dp(path, pos + 1, 0) + path[pos][2]);
			}
		}
	}
	return memo[pos][state];
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> path(n, vector<int>(3, -1));
	char temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp == 'b') {
			path[i][0] = 0;
		} else {
			path[i][0] = 1;
		}
		cin >> path[i][1];
		if (cin.get() != '\n') {
			cin >> path[i][2];
		}
	}
	//     检测输入
	//     for (auto p : path) {
	//         cout << p[0] << ' ' << p[1] << ' ' << p[2] << endl;
	//     }
	memo.resize(n, vector<int>(m + 1, -1));
	cout << dp(path, 0, 0) << endl;
	return 0;
}