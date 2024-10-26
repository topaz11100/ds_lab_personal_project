#include "refrigerator.h"

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

void refrigerator::print()
{
	cout << endl << "refrigerator status" << endl;
	cout << "has " << length << " foods" << endl;
	cout << "food list" << endl;
	for (const food& f : expiry_set)
	{
		cout << f << endl;
	}
	cout << endl;
}