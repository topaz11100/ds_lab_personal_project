#include "file_manage.h"

string get_recipy(const string& key)
{
	ifstream ifs{ recipe_path + key + recipe_extension };
	if (!ifs.is_open())
	{
		throw runtime_error("recipe file open error");
	}

	string result = key + " recipe\n";

	string temp = "";
	while (getline(ifs, temp))
	{
		result += temp + "\n";
	}
	return result;
}

void set_recipe_use_cin(const string& key)
{
	ofstream ofs{ recipe_path + key + recipe_extension };
	if (!ofs.is_open())
	{
		throw runtime_error("recipe file open error");
	}
	cout << "�����Ǹ� �Է��ϼ��� end�� �Է��� ����" << endl;
	while (true)
	{
		string temp = "";
		getline(cin, temp);
		if (temp == "end")
		{
			break;
		}
		ofs << temp << endl;
	}
}

food get_food(const string& key)
{
	ofstream ofs{ food_path + key + food_extension, ios::binary };
	if (!ofs.is_open())
	{
		throw runtime_error("food file open error");
	}

}