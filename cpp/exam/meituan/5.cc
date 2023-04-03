#include <bits/stdc++.h>

using namespace std;

class Node {
public:
	int id;
	int val = 0;
	bool red;
	vector<Node*> childs;
	Node* father;

	Node(int id_) { id = id_; }
	Node() {}
};

int dfs(Node* node) {
	if (node->childs.empty()) {
		node->val = 1;
		return 1;
	}

	for (auto child : node->childs) {
		dfs(child);
	}

	if (node->red) {
		node->val = 0;
		for (auto child : node->childs) {
			node->val += child->val;
		}
	} else {
		// 可以改改
		node->val = node->childs[0]->val ^ node->childs[1]->val;
	}
	return node->val;
}

int main() {
	int n, fa, color;
	cin >> n;
	vector<Node*> tree(n);
	for (int i = 0; i < n; i++) {
		tree[i] = new Node(i + 1);
	}
	for (int i = 1; i < n; i++) {
		cin >> fa;

		tree[i]->father = tree[fa - 1];
		tree[fa - 1]->childs.emplace_back(tree[i]);
	}

	for (int i = 0; i < n; i++) {
		cin >> color;
		tree[i]->red = (color == 1);
	}

	cout << dfs(tree[0]) << endl;
}
