#include "refrigerator.h"

multiset<food>::iterator refrigerator::index_it(int index)
{
	auto result = expiry_set.begin();
	advance(result, index);
	return result;
}

void refrigerator::push(const food& f)
{
	lock_guard<mutex> lock(mtx);

	expiry_set.insert(f);
}

food refrigerator::pop(const string& name)
{
	lock_guard<mutex> lock(mtx);

	for (auto& f : expiry_set)
	{
		if (f.get_name() == name)
		{
			return f;
		}
	}
}

food refrigerator::pop(int index)
{
	lock_guard<mutex> lock(mtx);

	auto it = index_it(index);
	food result{ *it };
	expiry_set.erase(it);
	return result;
}

void refrigerator::minus_expiry()
{
	lock_guard<mutex> lock(mtx);

	int del_count = 0;

	for (auto& f : expiry_set)
	{
		int expiry = f.get_expiry() - 1;
		f.set_expiry(expiry);

		if (expiry == f.remin_expiry())
		{
			remin_set.push(&f);
		}
		else if (expiry <= 0)
		{
			alert_set.push(f);
			del_count += 1;
		}
	}

	for (int i = 0; i < del_count; i += 1)
	{
		expiry_set.erase(expiry_set.begin());
	}
}

const food& refrigerator::operator[](int index)
{
	lock_guard<mutex> lock(mtx);

	auto it = index_it(index);
	return *it;
}

void refrigerator::print()
{
	lock_guard<mutex> lock(mtx);

	cout << "냉장고 상태\n";
	cout << length() << " 개 음식이 있습니다\n";
	for (auto& f : expiry_set)
	{
		cout << f << '\n';
	}
}

food refrigerator::pop_alert_set()
{
	lock_guard<mutex> lock(mtx);

	food result{ alert_set.front() };
	alert_set.pop();
	return result;
}

food refrigerator::pop_remin_set()
{
	lock_guard<mutex> lock(mtx);

	food result{ *(remin_set.front()) };
	remin_set.pop();
	return result;
}