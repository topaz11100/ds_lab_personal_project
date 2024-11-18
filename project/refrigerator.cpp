#include "refrigerator.h"

mutex refri;

void refrigerator::push(const food& f)
{
	
	expiry_set.insert(f);
	length += 1;
}

food refrigerator::pop(const string& name)
{
	
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
	
	auto it = expiry_set.begin();
	advance(it, index);
	food result{ *it };
	expiry_set.erase(it);
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

void refrigerator::over_expiry(vector<int>& v)
{
	
	v.clear();
	for (int i = 0; i < length; i += 1)
	{
		if ((*this)[i].get_expiry() <= 0)
		{
			v.push_back(i);
		}
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