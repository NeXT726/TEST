#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long>> memo;
int num;

long long dp(string& str, int pos, int n) {
	if (pos == str.length() && n == 0) {
		return 1;
	}
	if (((pos + n) / 2) > num || pos == str.length() || n < 0) {
		return 0;
	}
	if (memo[pos][n] == -1) {
		if (str[pos] == '(')
			memo[pos][n] = dp(str, pos + 1, n + 1);
		else if (str[pos] == ')')
			memo[pos][n] = dp(str, pos + 1, n - 1);
		else if (str[pos] == '?') {
			memo[pos][n] = dp(str, pos + 1, n + 1) + dp(str, pos + 1, n - 1);
		}
	}
	return memo[pos][n];
}

int main() {
	string str;
	cin >> str;
	if (str.length() % 2) {
		return 0;
	}
	num = str.length() / 2;

	memo.resize(str.length(), vector<long long>(num, -1));
	long long cnt = dp(str, 0, 0);

	cout << cnt % 1000000007 << endl;
}
// 64 位输出请用 printf("%lld")