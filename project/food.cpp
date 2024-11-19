#include "food.h"

food::food(const string& n, const int& e)
{
	name = n;
	expiry = new int{ e };
	remin_time = min(e / 2, remin_thre);
}

food::food(const food& f)
{
	name = f.name;
	expiry = new int{ f.get_expiry() };
	remin_time = f.remin_expiry();
}

food& food::operator=(const food& f)
{
	name = f.name;
	*expiry = f.get_expiry();
	remin_time = f.remin_expiry();
	return *this;
}

food::~food()
{
	delete expiry;
}

bool operator <(const food& a, const food& b)
{
	return a.get_expiry() < b.get_expiry();
}

ostream& operator <<(ostream& os, const food& f)
{
	os << "이름 : " << f.get_name() << " 기한 : " << f.get_expiry();
	return os;
}

food_bin::food_bin(const food& f)
{
	this->expiry = f.get_expiry();
	this->name = f.get_name();
	this->name_length = (this->name).size();
}

food_bin food_to_bin(const food& f)
{
	return food_bin{ f };
}
food bin_to_food(const food_bin& fb)
{
	return food{ fb.name, fb.expiry };
}