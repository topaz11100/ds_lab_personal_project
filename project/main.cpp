#include "base.h"
#include "food.h"
#include "refrigerator.h"
#include "file_manage.h"
#include "Time.h"

int main() {
	
	for (int i = 0; i < 5; i += 1)
	{
		vector<string> input;
		cout << "가져올 레시피 입력\n주재료 레시피 로 입력" << endl;
		input_to_vector(cin, input);
		cout << get_recipe(input[0], input[1]) << endl << endl;
	}

	return 0;
}

