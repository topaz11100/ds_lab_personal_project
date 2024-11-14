#include "base.h"
#include "food.h"
#include "refrigerator.h"
#include "file_manage.h"
#include "Time.h"

int main() {
	
	for (int i = 0; i < 5; i += 1)
	{
		vector<string> v;
		cout << "음식 레시피 설정" << endl;
		cout << "주재로 레시피 이름 입력" << endl;
		input_to_vector(cin, v);
		r.push(get_food(v[0]));
		r.print();
	}

	return 0;
}

