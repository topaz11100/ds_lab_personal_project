#pragma once
#include "base.h"
#include "food.h"

const string food_path = "data/food/";
const string food_extension = ".bin";
const string recipe_path = "data/recipe/";
const string recipe_extension = ".txt";

void input_to_vector(istream& in, vector<string>& v);

string get_recipe(const string& key1, const string& key2);
void set_recipe_use_cin();

food get_food(const string& key);
void set_food_use_cin();

void set_food(const food& f, const string& key);
