#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> nums(n, -1);
	vector<bool> p(n, false);
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp >= 0) {
			p[i] = true;
		}
		while (temp) {
			nums[i]++;
			temp = temp / 2;
		}
	}

	vector<vector<int>> mul(n, vector<int>(n, 0));
	vector<vector<bool>> mul_p(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++) {
		mul[i][i] = nums[i];
		mul_p[i][i] = p[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (nums[j] != -1 && mul[i][j - 1] != -1) {
				mul[i][j] = nums[j] + mul[i][j - 1];
			} else {
				mul[i][j] = -1;
			}

			mul_p[i][j] = (p[j] == mul_p[i][j - 1]);
		}
	}

	int res = 0;
	int left = 0, right = -1;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (mul_p[i][j] && mul[i][j] != -1) {
				if (mul[i][j] > res) {
					res = mul[i][j];
					left = i;
					right = j;
				} else if (mul[i][j] == res) {
					if ((j - i) > (right - left) ||
					    ((j - i) == (right - left) && (i > left))) {
						left = i;
						right = j;
					}
				}
			}
		}
	}

	if ((right - left) >= 0) {
		cout << left << ' ' << right;
	} else {
		cout << -1;
	}
}