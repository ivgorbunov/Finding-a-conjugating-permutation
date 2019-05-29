#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<int>> pemrmutation1;
vector<vector<int>> pemrmutation2;

vector<vector<int>> g1;
vector<vector<int>> g2;

vector<bool> used1;
vector<bool> used2;

vector<int> now;

bool comp(vector<int> arr1, vector<int> arr2) {
	if (arr1.size() <= arr2.size()) {
		return true;
	} else {
		return false;
	}
}

void dfs1(int v) {
	used1[v] = true;
	now.push_back(v);
	for (auto u: g1[v]) {
		if (!used1[u]) {
			dfs1(u);
		}
	}
}

void dfs2(int v) {
	used2[v] = true;
	now.push_back(v);
	for (auto u: g2[v]) {
		if (!used2[u]) {
			dfs2(u);
		}
	}
}

signed main() {
	int n;
	cin >> n;

	g1.resize(n);
	g2.resize(n);

	pemrmutation1.resize(n);
	pemrmutation2.resize(n);

	used1.resize(n);
	used2.resize(n);

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		g1[i].push_back(a - 1);
	}
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		g2[i].push_back(a - 1);
	}

	for (int i = 0; i < n; i++) {
		if (!used1[i]) {
			now.clear();
			dfs1(i);
			pemrmutation1.push_back(now);
		}
	}
	for (int i = 0; i < n; i++) {
		if (!used2[i]) {
			now.clear();
			dfs2(i);
			pemrmutation2.push_back(now);
		}
	}

	if (pemrmutation1.size() != pemrmutation2.size()) {
		cout << "types are different \n";
		return 0;
	}

	sort(pemrmutation1.begin(), pemrmutation1.end(), comp);
	sort(pemrmutation2.begin(), pemrmutation2.end(), comp);

	for (int i = 0; i < pemrmutation1.size(); i++) {
		if (pemrmutation1[i].size() != pemrmutation2[i].size()) {
			cout << "types are different \n";
			return 0;
		}
	}

	vector<int> ans1;
	vector<int> ans2;

	for (int i = 0; i < pemrmutation1.size(); i++) {
		for (int j = 0; j < pemrmutation1[i].size(); j++) {
			ans1.push_back(pemrmutation1[i][j]);
			ans2.push_back(pemrmutation2[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		cout << ans1[i] + 1 << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << ans2[i] + 1 << " ";
	}
}