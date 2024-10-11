#include "base.h"
#include "food.h"
#include <set>

void up(multiset<food>& r, vector<food*> a, string s, int i) {
	food* f = new food{s, i};
	r.insert(*f);
	a.push_back(f);
}

int main() {
	multiset<food> r;
	vector<food*> a;
	up(r, a, "apple", 3);
	up(r, a, "banana", 2);
	up(r, a, "cherry", 1);
	up(r, a, "date", 4);
	up(r, a, "elderberry", 5);
	up(r, a, "fig", 6);

	for (auto& b : r)
		*(b.expiry) += 1;

	for (auto& b : r)
		cout << b << endl;

	return 0;
}