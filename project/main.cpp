#include "base.h"
#include "food.h"
#include "refrigerator.h"
#include "file_manage.h"

int main() {

	refrigerator r;
	
	for (int i = 0; i < 5; i += 1)
	{
		vector<string> v;
		cout << "가져올 음식 이름을 입력하세요" << endl;
		input_to_vector(cin, v);
		r.push(get_food(v[0]));
		r.print();
	}

	cout << "1 second later" << endl;
	r.minus_expiry();
	r.print();

	cout << "5 second later" << endl;
	for (int i = 0; i < 5; i += 1)
	{
		r.minus_expiry();
	}
	r.print();

	return 0;
}

