#pragma once

#include "base.h"

class food
{
public:
	food(const string& n, const int& e);

	void set_expiry(const int& new_expiry) const { *expiry = new_expiry; }

	const string& get_name() const { return name; }
	int get_expiry() const { return *expiry; }
	
private:
	string name;
	shared_ptr<int> expiry;
};
bool operator <(const food& a, const food& b);
ostream& operator <<(ostream& os, const food& f);

struct food_bin
{
	food_bin(const int& expiry, const int& name_length, const string& name);
	int expiry;
	int name_length;
	string name;
};

food_bin food_to_bin(const food& f);
food bin_to_food(const food_bin& fb);

