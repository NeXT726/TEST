#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> nums(n, 0);
	for (auto& num : nums) {
		cin >> num;
	}

	vector<long long> presum(n, 0);
	presum[0] = nums[0];
	for (int i = 1; i < n; i++) {
		presum[i] = (presum[i - 1] + nums[i]) % 1000000007;
	}

	long long res = 0;

	for (long long i = 1; i < presum.size(); i++) {
		res += (presum[i - 1] * nums[i]) % 1000000007;
		res = res % 1000000007;
	}

	cout << res;
	return 0;
}