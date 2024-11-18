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
	void over_expiry(vector<int>& v);

	const food& operator[](const int& index);
	int get_length() const { return length; }

	void print();

private:
	multiset<food> expiry_set;
	int length;
};



