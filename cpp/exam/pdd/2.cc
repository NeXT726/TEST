#include <bits/stdc++.h>

using namespace std;

int cnt = 0;

void count(vector<vector<int>>& path, int now) {
	if (path[now].empty()) {
		cnt++;
		return;
	}
	for (auto i : path[now]) {
		count(path, i);
	}
	return;
}

bool del(vector<vector<int>>& path, vector<vector<bool>>& can, int now) {
	if (path[now].empty()) {
		return true;
	}
	bool res = true;
	for (int i = 0; i < path[now].size(); i++) {
		bool temp = del(path, can, path[now][i]);
		if (can[now][i] == true && temp == true) {
			path[now].erase(path[now].begin() + i);
			can[now].erase(can[now].begin() + i);
			i--;
		} else {
			res = false;
		}
	}
	return res;
}

int main() {
	int n;
	cin >> n;

	vector<vector<int>> path(n + 1);
	vector<vector<bool>> can(n + 1);
	int begin, end, t;
	while (cin >> begin >> end >> t) {
		path[begin].emplace_back(end);
		can[begin].emplace_back((t == 0));
	}
	del(path, can, 1);
	//     for (auto p : path) {
	//         for (auto e : p) {
	//             cout << e << ' ';
	//         }
	//         cout << endl;
	//     }
	count(path, 1);
	cout << cnt;
}