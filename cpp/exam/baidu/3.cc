#include <bits/stdc++.h>

using namespace std;

struct Mul {
	uint64_t two_count = 0;
	uint64_t five_count = 0;

	void plus(const Mul& m) {
		two_count += m.two_count;
		five_count += m.five_count;
	}
};

Mul get_cnt(int val) {
	Mul res;
	while (val > 0) {
		if (val % 5 == 0) {
			res.five_count++;
			val /= 5;
		} else if (val % 2 == 0) {
			res.two_count++;
			val /= 2;
		} else {
			return res;
		}
	}
	return res;
}

struct Node {
	Mul val;
	Mul mul;
	vector<Node*> childs;

	Node(uint32_t v) { val = get_cnt(v); }
};

Mul dfs(Node* root) {
	root->val.plus(root->mul);
	for (auto child : root->childs) {
		child->mul.plus(root->mul);
		root->val.plus(dfs(child));
	}
	return root->val;
}

int main() {
	// 节点数量
	int n;
	cin >> n;
	// 所有节点
	vector<Node*> nodes(n);
	int tmp;
	for (auto& e : nodes) {
		cin >> tmp;
		e = new Node(tmp);
	}
	int in, out;
	for (int i = 0; i < (n - 1); i++) {
		cin >> in >> out;
		nodes[in - 1]->childs.emplace_back(nodes[out - 1]);
	}
	// 操作数
	int q;
	cin >> q;
	int which, m;
	for (int i = 0; i < q; i++) {
		cin >> which >> m;
		nodes[which - 1]->mul.plus(get_cnt(m));
	}

	dfs(nodes[0]);
	for (auto node : nodes) {
		cout << min(node->val.two_count, node->val.five_count) << ' ';
	}

	return 0;
}