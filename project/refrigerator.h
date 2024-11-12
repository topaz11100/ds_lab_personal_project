#pragma once
#include "base.h"
#include "food.h"

class refrigerator
{
public:
	refrigerator() :length(0) {}

	void push(const food& f);
	food pop();

	void minus_expiry();
	void over_expiry(vector<int>& v);

	const food& operator[](const int& index);
	int get_length() const { return length; }

	void print();

private:
	multiset<food> expiry_set;
	int length;
};



