#include "file_manage.h"

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

string recommend_recipe(const string& key)
{
	filesystem::path p = recipe_path + key;
	if (!filesystem::exists(p)) return "No Recipe";

	auto fp = filesystem::directory_iterator(p);
	int fd = rand() % distance(fp, filesystem::directory_iterator{});
	
	advance(fp, fd);

	return get_recipe(key, fp->path().filename().string());
}

string get_recipe(const string& key1, const string& key2)
{
	ifstream ifs{ recipe_path + key1 + "/" + key2 + recipe_extension};
	if (!ifs.is_open())
	{
		throw runtime_error("recipe file open error");
	}

	string result = key1 + " " + key2 + " recipe\n";

	string temp = "";
	while (getline(ifs, temp))
	{
		result += temp + "\n";
	}
	return result;
}

void set_recipe_use_cin()
{
	vector<string> input_temp;
	cout << "주재료, 레시피 이름 입력\n(주재료 이름) (레시피 이름)\n";
	input_to_vector(cin, input_temp);

	filesystem::path p = recipe_path + input_temp[0];
	filesystem::create_directories(p);

	ofstream ofs{ recipe_path + input_temp[0] + "/" + input_temp[1] + recipe_extension};
	if (!ofs.is_open())
	{
		throw runtime_error("recipe file open error");
	}
	cout << "레시피를 입력하세요 end를 입력해 종료" << endl;
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
	ifstream ifs{ food_path + key + food_extension, ios::binary };
	if (!ifs.is_open())
	{
		throw runtime_error("food file open error");
	}
	int expiry, name_length;
	ifs.read(reinterpret_cast<char*>(&expiry), sizeof(int));
	ifs.read(reinterpret_cast<char*>(&name_length), sizeof(int));
	string name(name_length, '\0');
	ifs.read(reinterpret_cast<char*>(&name[0]), name_length);
	food result{ name, expiry };
	cout << endl << name <<  " loaded" << endl << endl;
	return result;
}

void set_food_use_cin()
{
	vector<string> input_temp;
	cout << "음식 입력\n(음식 이름) (기한)\n";
	input_to_vector(cin, input_temp);
	food f{ input_temp[0], stoi(input_temp[1]) };
	set_food(f, f.get_name());
}

void set_food(const food& f, const string& key)
{
	ofstream ofs{ food_path + key + food_extension, ios::binary };
	if (!ofs.is_open())
	{
		throw runtime_error("food file open error");
	}
	food_bin fb{ food_to_bin(f) };
	ofs.write(reinterpret_cast<const char*>(&fb.expiry), sizeof(int));
	ofs.write(reinterpret_cast<const char*>(&fb.name_length), sizeof(int));
	ofs.write(reinterpret_cast<const char*>(fb.name.c_str()), fb.name_length);
	cout << endl << f.get_name() << food_extension << " saved" << endl << endl;
}

