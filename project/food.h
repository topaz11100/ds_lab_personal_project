#pragma once

#include "base.h"

class food
{
public:
	food(const string& n, const int& e);
	food(const food& f);
	food& operator=(const food& f);
	~food();

	int get_expiry() const { return *expiry; }
	void set_expiry(const int& new_expiry) const { *expiry = new_expiry; }

	const string& get_name() const { return name; }

	int remin_expiry() const { return remin_time; }

	static const int remin_thre = 5;

private:
	string name;
	int* expiry;
	int remin_time;
};
bool operator <(const food& a, const food& b);
ostream& operator <<(ostream& os, const food& f);

struct food_bin
{
	food_bin(const food& f);
	int expiry;
	int name_length;
	string name;
};

food_bin food_to_bin(const food& f);
food bin_to_food(const food_bin& fb);

