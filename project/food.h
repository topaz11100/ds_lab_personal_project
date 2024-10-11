#pragma once

#include "base.h"

class food{
public:

	food(string name, int expiry) : name{ name }, expiry{ expiry } {}

	string get_name() const { return name; }
	int get_expiry() const { return expiry; }

public:
	string name;
	int expiry;
};

bool operator <(const food& a, const food& b) {
	return a.get_expiry() < b.get_expiry();
}

ostream& operator <<(ostream& os, const food& f) {
	os << f.get_name() << " " << f.get_expiry();
	return os;
}


