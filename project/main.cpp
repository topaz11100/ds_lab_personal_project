#include "base.h"
#include "refrigerator.h"
#include "food.h"
#include "file_manage.h"

int main() {
	set_recipe_use_cin("test");
	cout << get_recipy("test") << endl;
	
	return 0;
}