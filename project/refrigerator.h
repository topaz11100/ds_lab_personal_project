#pragma once
#include "base.h"
#include "food.h"

class refrigerator
{
public:
	refrigerator() {}

	void push(const food& f);

	food pop(const string& name);
	food pop(int index);

	void minus_expiry();

	const food& operator[](int index);
	int length() const { return expiry_set.size(); }

	void print();

	bool is_alert_empty() const { return alert_set.empty(); }
	bool is_remin_empty() const { return remin_set.empty(); }

	food pop_alert_set();
	food pop_remin_set();

private:
	multiset<food> expiry_set;
	queue<food> alert_set;
	queue<const food*> remin_set;

	mutex mtx;

	multiset<food>::iterator index_it(int index);
};



