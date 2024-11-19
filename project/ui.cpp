#include "ui.h"

void input_to_vector(istream& in, vector<string>& v)
{
	v.clear();
	string temp;
	getline(in, temp);
	stringstream ss{ temp };

	if (temp.empty())
	{
		return; // 아무 것도 하지 않고 바로 리턴
	}

	for (string word; ss >> word;)
	{
		v.push_back(word);
	}
}

void menu_promft()
{
	cout << "냉장고 메뉴 선택\n";
	cout << "1. 전체 음식 보기\n";
	cout << "2. 음식 넣기\n";
	cout << "3. 음식 꺼내기\n";
	cout << "4. 레시피 보기\n";
	cout << "5. 기한 하위 5개 보기\n";
	cout << "6. 음식 설정\n";
	cout << "7. 레시피 설정\n";
	cout << "8. 종료\n";
	cout << "메뉴 선택 (정수 입력) : \n";
}

void print_all_food(refrigerator& r)
{
	r.print();
}

void push_food(refrigerator& r)
{
	vector<string> food_list;
	save_path_ls(food_list, food_path);

	cout << "음식 목록\n";
	for (auto& x : food_list)
	{
		cout << x << '\n';
	}


}

void print_5_food(refrigerator& r)
{
	int thre = min(5, r.length());
	cout << "기한이 얼마 남지 않은 음식\n";
	for (int i = 0; i < thre; i += 1)
	{
		cout << r[i] << '\n';
	}
	cout << endl;
}

void program_off()
{
	second_condition = true;
	alert = true;
	reminder = true;

	off = true;
	cv.notify_all();

	cout << "냉장고 종료" << endl;
}

