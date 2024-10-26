#pragma once

#include "base.h"

class food{
public:

	food(const string& name, const int& expiry);

	void set_expiry(const int& expiry) const { *(this->expiry) = expiry; }

	const string& get_name() const { return name; }
	int get_expiry() const { return *expiry; }
	
private:
	string name;
	shared_ptr<int> expiry;
};

food::food(const string& name, const int& expiry)
{
	this->name = name;
	this->expiry = make_shared<int>(expiry);
}

bool operator <(const food& a, const food& b) {
	return a.get_expiry() < b.get_expiry();
}

ostream& operator <<(ostream& os, const food& f) {
	os << "Name : " << f.get_name() << " Expiry : " << f.get_expiry();
	return os;
}


