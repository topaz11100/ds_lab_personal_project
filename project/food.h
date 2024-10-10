#pragma once

#include "base.h"

class food{
public:

	string get_name() const { return name; }
	int get_expiry() const { return expiry; }

	bool operator <(const food& b) {
		return expiry > b.expiry;
	}
private:
	string name;
	int expiry;
};


