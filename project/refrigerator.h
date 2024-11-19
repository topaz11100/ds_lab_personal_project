#pragma once
#include "base.h"
#include "food.h"

//멤버에 뮤텍스 넣어서 동기화메서드로 만들것

class refrigerator
{
public:
	refrigerator() : length(0) {}

	void push(const food& f);
	food pop(const string& name);
	food pop(const int& index);

	void minus_expiry();

	const food& operator[](const int& index);
	int get_length() const { return length; }

	void print();

	bool is_alert_empty() const { return alert_set.empty(); }
	bool is_remin_empty() const { return remin_set.empty(); }

	food pop_alert_set();
	food pop_remin_set();

	static const int REMIN = 5;

private:
	multiset<food> expiry_set;
	queue<food> remin_set;
	queue<food> alert_set;
	int length;

	mutex mtx;
};



