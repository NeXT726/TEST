#include <bits/stdc++.h> //C++

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<bool> nums(n + 1, true);
	nums[1] = false;
	for (int i = 2; i < n / 2; i++) {
		if (nums[i]) {
			for (int now = (2 * i); now <= n; now += i) {
				nums[now] = false;
			}
		}
	}
	for (int i = (n - 1); i > 3; i--) {
		if (nums[i]) {
			for (int j = 2; j < i; j++) {
				if (nums[j] && nums[i - j]) {
					cout << j << ' ' << (i - j) << endl;
					return 0;
				}
			}
		}
	}
	cout << -1;
	return 0;
}