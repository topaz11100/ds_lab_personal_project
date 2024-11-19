#include "refrigerator.h"


void refrigerator::push(const food& f)
{
	lock_guard<mutex> lock(mtx);
	expiry_set.insert(f);
	length += 1;
}

food refrigerator::pop(const string& name)
{
	lock_guard<mutex> lock(mtx);
	for (auto it = expiry_set.begin(); it != expiry_set.end(); ++it)
	{
		if (it->get_name() == name)
		{
			food result{ *it };
			expiry_set.erase(it);
			length -= 1;
			return result;
		}
	}
}

food refrigerator::pop(const int& index)
{
	lock_guard<mutex> lock(mtx);
	auto it = expiry_set.begin();
	advance(it, index);
	food result{ *it };
	expiry_set.erase(it);
	length -= 1;
	return result;
}

void refrigerator::minus_expiry()
{
	lock_guard<mutex> lock(mtx);
	int del_count = 0;

	for (auto& f : expiry_set)
	{
		int expiry = f.get_expiry();
		f.set_expiry(expiry - 1);

		if (expiry == 0)
		{
			alert_set.push(f);
			del_count += 1;
		}
		else if (expiry == REMIN)
		{
			remin_set.push(f);
		}
	}

	for (int i = 0; i < del_count; i += 1)
	{
		expiry_set.erase(expiry_set.begin());
		length -= 1;
	}
}

const food& refrigerator::operator[](const int& index)
{
	lock_guard<mutex> lock(mtx);
	auto it = expiry_set.begin();
	advance(it, index);
	return *it;
}

void refrigerator::print()
{
	lock_guard<mutex> lock(mtx);
	cout << endl << "refrigerator status" << endl;
	cout << "has " << length << " foods" << endl;
	cout << "food list" << endl;
	for (const food& f : expiry_set)
	{
		cout << f << endl;
	}
	cout << endl;
}

food refrigerator::pop_alert_set()
{
	lock_guard<mutex> lock(mtx);
	food result = alert_set.front();
	alert_set.pop();
	return result;
}

food refrigerator::pop_remin_set()
{
	lock_guard<mutex> lock(mtx);
	food result = remin_set.front();
	remin_set.pop();
	return result;
}