#pragma once
#include "base.h"
#include "food.h"
#include "ui.h"

const string food_path = "data/food/";
const string food_extension = ".bin";
const string recipe_path = "data/recipe/";
const string recipe_extension = ".txt";

void save_path_ls(vector<string>& p, const string& path);

string recommend_recipe(const string& key);

string get_recipe(const string& key1, const string& key2);
void set_recipe_use_cin(const string& food, const string& reci);

food get_food(const string& key);

void set_food_use_cin(const string& key);

void set_food(const food& f);
