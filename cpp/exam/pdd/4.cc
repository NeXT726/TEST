#include <bits/stdc++.h>

using namespace std;

int main() {
	int tn;
	cin >> tn;
	while (tn > 0) {
		unordered_set<int> zero;
		zero.insert(0);
		queue<int> q;

		int n, res = 0;
		cin >> n;
		int now;
		while (n > 0) {
			cin >> now;
			if (zero.count(now)) {
				now = 0;
			}
			if (!q.empty() && q.back() > now) {
				while (!q.empty()) {
					if (!zero.count(q.front())) {
						zero.insert(q.front());
						res++;
					}
					q.pop();
				}
			}
			if (zero.count(now)) {
				now = 0;
			}
			q.push(now);
			n--;
		}
		cout << res << endl;
		zero.clear();
		tn--;
	}
}