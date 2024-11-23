#include "ui.h"

void input_to_vector(istream& in, vector<string>& v)
{
	v.clear();
	string temp;
	getline(in, temp);
	stringstream ss{ temp };

	if (temp.empty())
	{
		return; // �ƹ� �͵� ���� �ʰ� �ٷ� ����
	}

	for (string word; ss >> word;)
	{
		v.push_back(word);
	}
}

void menu_promft()
{
	cout << "\n����� �޴� ����\n";
	cout << "1. ��ü ���� ����\n";
	cout << "2. ���� �ֱ�\n";
	cout << "3. ���� ������\n";
	cout << "4. ������ ����\n";
	cout << "5. ���� ���� 5�� ����\n";
	cout << "6. ���� ����\n";
	cout << "7. ������ ����\n";
	cout << "8. ����\n";
	cout << "�޴� ���� (���� �Է�) : ";
}

void print_food_list()
{
	vector<string> food_list;
	save_path_ls(food_list, food_path);
	cout << "\n���� ���� ���\n";
	for (auto& f : food_list)
	{
		cout << f << '\n';
	}
}

void print_all_food(refrigerator& r)
{
	r.print();
}

void push_food(refrigerator& r)
{
	print_food_list();
	cout << "����� ���� ������ �����ϼ���\n�̸� �Է� : ";
	vector<string> food_name;
	input_to_vector(cin, food_name);

	r.push(get_food(food_name[0]));
}

void pop_food(refrigerator& r)
{
	print_all_food(r);

	cout << "������� ���� ������ �����ϼ���\n�̸� �Է� : ";
	vector<string> food_name;
	input_to_vector(cin, food_name);

	try
	{
		r.pop(food_name[0]);
	}
	catch (out_of_range& e)
	{
		cout << e.what() << endl;
	}

	cout << "��õ ������\n";
	cout << recommend_recipe(food_name[0]);
}

void save_food()
{
	print_food_list();
	cout << "�� �̸����� ����, ���� �̸����� ����\n";
	cout << "���� �̸� �Է� : ";
	vector<string> food_name;
	input_to_vector(cin, food_name);

	cout << endl;
	set_food_use_cin(food_name[0]);
}

string print_recipe_list()
{
	string food_name;

	vector<string> input;
	print_food_list();
	cout << "������ ����� ���� ���� ���� �Է�\n�̸� �Է� : ";
	input_to_vector(cin, input);
	food_name = input[0];
	
	cout << '\n' << food_name << " �� ������ ���\n";
	save_path_ls(input, recipe_path + input[0]);
	for (auto& f : input)
	{
		cout << f << '\n';
	}
	return food_name;
}

void print_recipe()
{
	string food_name = print_recipe_list();
	
	cout << "�� �����Ǹ� ����\n�̸� �Է� : ";
	vector<string> input;
	input_to_vector(cin, input);

	cout << endl << get_recipe(food_name, input[0]) << endl;
}

void save_recipe()
{
	string food_name = print_recipe_list();

	cout << "������ ������ �Է�\n�̸� �Է� : ";
	vector<string> input;
	input_to_vector(cin, input);

	set_recipe_use_cin(food_name, input[0]);
}

void print_5_food(refrigerator& r)
{
	int thre = min(5, r.length());
	cout << "\n������ �� ���� ���� ����\n";
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

	cout << "����� ����" << endl;
}

