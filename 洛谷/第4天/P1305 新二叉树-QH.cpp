#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

int n;
int p = 0;

class node {
public:
	char ch;
	node* l;
	node* r;
	node(char c = '\0') { ch = c; l = r = NULL; }
};

void f(node* t) {
	if (t == NULL)
		return;
	cout << t->ch;
	f(t->l);
	f(t->r);
}

void func(char* arr, int a, node** end) {
	if (--n == 0)
		return;
	node* t = end[a];
	end[a] = NULL;
	node* t1;
	node* t2;
	if (arr[1] != '*') {
		t1 = new node(arr[1]);
		t->l = t1;
		end[a] = t1;
		a = -1;
	}
	if (arr[2] != '*') {
		t2 = new node(arr[2]);
		t->r = t2;
		if (a == -1)
			end[p++] = t2;
		else
			end[a] = t2;
	}
	char* s = new char[4];
	cin >> s;
	int i;
	for (i = 0; end[i] == NULL || end[i]->ch != s[00]; i++)
		cout << end[i]->ch;
	func(arr, i, end);
}

int main() {
	cin >> n;
	char* arr = new char[4];
	node** end = new node*[2 * n];
	for (int i = 0; i < n; i++) end[i] = NULL;
	cin >> arr;
	node* root = new node(arr[0]);
	end[p++] = root;
	func(arr, 0, end);
	f(root);
	cout << "#" << endl;
	while (1);
	return 0;
}
