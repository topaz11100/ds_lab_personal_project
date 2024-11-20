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
	cout << "\n냉장고 메뉴 선택\n";
	cout << "1. 전체 음식 보기\n";
	cout << "2. 음식 넣기\n";
	cout << "3. 음식 꺼내기\n";
	cout << "4. 레시피 보기\n";
	cout << "5. 기한 하위 5개 보기\n";
	cout << "6. 음식 설정\n";
	cout << "7. 레시피 설정\n";
	cout << "8. 종료\n";
	cout << "메뉴 선택 (정수 입력) : ";
}

void print_food_list()
{
	vector<string> food_list;
	save_path_ls(food_list, food_path);
	cout << "\n현재 음식 목록\n";
	for (auto& f : food_list)
	{
		cout << f << '\n';
	}
}

string print_recipe_list()
{
	string result;

	vector<string> input;
	save_path_ls(input, recipe_path);
	cout << "\n레시피가 등록된 음식 목록\n";
	for (auto& f : input)
	{
		cout << f << '\n';
	}

	cout << "레시피를 볼 재료를 선택하세요\n재료 이름 입력 : ";
	input_to_vector(cin, input);
	cout << "\n" << input[0] << " 레시피 목록\n";
	result = input[0];

	save_path_ls(input, recipe_path + input[0]);
	for (auto& f : input)
	{
		cout << f << '\n';
	}

	return result;
}

void print_all_food(refrigerator& r)
{
	r.print();
}

void push_food(refrigerator& r)
{
	print_food_list();
	cout << "냉장고에 넣을 음식을 선택하세요\n이름 입력 : ";
	vector<string> food_name;
	input_to_vector(cin, food_name);

	r.push(get_food(food_name[0]));
}

void pop_food(refrigerator& r)
{
	print_all_food(r);

	cout << "냉장고에서 꺼낼 음식을 선택하세요\n이름 입력 : ";
	vector<string> food_name;
	input_to_vector(cin, food_name);

	r.pop(food_name[0]);

	cout << "추천 레시피\n";
	cout << recommend_recipe(food_name[0]);
}

void save_food()
{
	print_food_list();
	cout << "새 이름으로 생성, 기존 이름으로 수정\n";
	cout << "음식 이름 입력 : ";
	vector<string> food_name;
	input_to_vector(cin, food_name);

	set_food_use_cin(food_name[0]);
}

void print_recipe()
{
	string food = print_recipe_list();
	
	cout << "볼 레시피를 선택하세요\n이름 입력 : ";
	vector<string> input;
	input_to_vector(cin, input);

	cout << get_recipe(food, input[0]) << endl;
}

void save_recipe()
{
	string food = print_recipe_list();

	cout << "새 이름으로 생성, 기존 이름으로 수정\n";
	cout << "레시피 이름 입력 : ";
	vector<string> recipe_name;
	input_to_vector(cin, recipe_name);

	set_recipe_use_cin(food, recipe_name[0]);
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

