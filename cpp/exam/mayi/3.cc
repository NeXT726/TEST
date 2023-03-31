#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// first[f][0] > second[s][0]
int binary(vector<vector<int>>& nums, int begin, int target) {
	int left = begin, right = nums.size() - 1, medium;

	while (left <= right) {
		medium = left + (right - left) / 2;
		if (nums[medium][0] > target) {
			right = medium - 1;
		} else if (nums[medium][0] < target) {
			left = medium + 1;
		} else {
			left = medium + 1;
		}
	}
	return left;
}

int main() {
	int m, n;
	cin >> m >> n;

	vector<vector<int>> first(m, vector<int>(2, 0));
	vector<vector<int>> second(n, vector<int>(2, 0));
	while (m > 0) {
		cin >> first[m - 1][0] >> first[m - 1][1];
		m--;
	};
	while (n > 0) {
		cin >> second[n - 1][0] >> second[n - 1][1];
		n--;
	}
	sort(first.begin(), first.end());
	sort(second.begin(), second.end());

	long long res = 0;
	int left = 0, right = 0;
	while (left < first.size() && right < second.size()) {
		if (first[left][0] > second[right][1]) {
			right++;
		} else if (first[left][1] < second[right][0]) {
			left++;
		} else if (first[left][0] < second[right][0]) {
			res += binary(second, right, first[left][1]) - right;
			left++;
		} else if (first[left][0] >= second[right][0]) {
			res += binary(first, left, second[right][1]) - left;
			right++;
		}
	}
	cout << res << endl;
	return 0;
}
