#include "file_manage.h"

void save_path_ls(vector<string>& p, const string& path)
{
	p.clear();
	for (const auto& entry : filesystem::directory_iterator(path))
	{
		p.push_back(entry.path().filename().string());
	}
}

string recommend_recipe(const string& key)
{
	filesystem::path p = recipe_path + key;
	if (!filesystem::exists(p)) return "No Recipe";

	auto fp = filesystem::directory_iterator(p);
	int fd = rand() % distance(fp, filesystem::directory_iterator{});
	
	advance(fp, fd);

	return get_recipe(key, fp->path().stem().string());
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

void set_recipe_use_cin(const string& food, const string& reci)
{

	filesystem::path p = recipe_path + food;
	filesystem::create_directories(p);

	ofstream ofs{ recipe_path + food + "/" + reci + recipe_extension};
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

void set_food_use_cin(const string& key)
{
	vector<string> input_temp;
	cout << key << "의 기한 입력 : ";
	input_to_vector(cin, input_temp);
	food f{ key, stoi(input_temp[0]) };
	set_food(f);
}

void set_food(const food& f)
{
	ofstream ofs{ food_path + f.get_name() + food_extension, ios::binary};
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

