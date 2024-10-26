#include "food.h"

food::food(const string& n, const int& e)
{
	name = n;
	expiry = make_shared<int>(e);
}

bool operator <(const food& a, const food& b)
{
	return a.get_expiry() < b.get_expiry();
}

ostream& operator <<(ostream& os, const food& f)
{
	os << "Name:" << f.get_name() << " Expiry:" << f.get_expiry();
	return os;
}

food_bin::food_bin(const int& expiry, const int& name_length, const string& name)
{
	this->expiry = expiry;
	this->name_length = name_length;
	this->name = name;
}

food_bin food_to_bin(const food& f)
{
	int expiry = f.get_expiry();
	string name = f.get_name();
	int name_length = name.size();
	return food_bin{ expiry, name_length, name };
}
food bin_to_food(const food_bin& fb)
{
	return food{ fb.name, fb.expiry };
}