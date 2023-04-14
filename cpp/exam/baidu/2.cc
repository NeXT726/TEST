#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int now = 1;
	string res;
	char c[] = {'r', 'e', 'd'};
	int i = 0;
	while (n != 0) {
		while (n >= now) {
			res.push_back(c[i]);
			n -= now;
			now++;
		}
		now = 1;
		i = (i + 1) % 3;
	}
	cout << res;
	return 0;
}