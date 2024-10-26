#pragma once
#include "base.h"
#include "food.h"

class refrigerator {
public:
	refrigerator() :length(0) {}

	void push(const food& f);
	food pop();

	void minus_expiry();

	int get_length() const { return length; }

	const food& operator[](const int& index);
private:
	multiset<food> expiry_set;
	int length;
};

void refrigerator::push(const food& f)
{
	expiry_set.insert(f);
	length += 1;
}

food refrigerator::pop()
{
	food result = *expiry_set.begin();
	expiry_set.erase(expiry_set.begin());
	length -= 1;
	return result;
}

void refrigerator::minus_expiry()
{
	for (auto& f : expiry_set)
	{
		f.set_expiry(f.get_expiry() - 1);
	}
}

const food& refrigerator::operator[](const int& index)
{
	auto it = expiry_set.begin();
	advance(it, index);
	return *it;
}

