#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<uint64_t>> res(n);
	uint64_t now = 1;
	for (int i = 0; i < n; i++) {
		res[i].resize(i + 1);
		res[i][0] = now;
		now *= 2;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < (i + 1); j++) {
			res[i][j] = now ^ res[i][j - 1] ^ res[i - 1][j - 1];
		}
	}

	for (auto e : res) {
		for (auto i : e) {
			cout << i << ' ';
		}
		cout << endl;
	}
	return 0;
}