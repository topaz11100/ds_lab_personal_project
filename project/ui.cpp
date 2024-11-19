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
	cout << "����� �޴� ����\n";
	cout << "1. ��ü ���� ����\n";
	cout << "2. ���� �ֱ�\n";
	cout << "3. ���� ������\n";
	cout << "4. ������ ����\n";
	cout << "5. ���� ���� 5�� ����\n";
	cout << "6. ���� ����\n";
	cout << "7. ������ ����\n";
	cout << "8. ����\n";
	cout << "�޴� ���� (���� �Է�) : \n";
}

void print_all_food(refrigerator& r)
{
	r.print();
}

void push_food(refrigerator& r)
{
	vector<string> food_list;
	save_path_ls(food_list, food_path);

	cout << "���� ���\n";
	for (auto& x : food_list)
	{
		cout << x << '\n';
	}


}

void print_5_food(refrigerator& r)
{
	int thre = min(5, r.length());
	cout << "������ �� ���� ���� ����\n";
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

