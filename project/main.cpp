#include "base.h"
#include "food.h"
#include "refrigerator.h"
#include "file_manage.h"
#include "Time.h"

int main() {
	
	for (int i = 0; i < 5; i += 1)
	{
		vector<string> v;
		cout << "���� ������ ����" << endl;
		cout << "����� ������ �̸� �Է�" << endl;
		input_to_vector(cin, v);
		r.push(get_food(v[0]));
		r.print();
	}

	return 0;
}

