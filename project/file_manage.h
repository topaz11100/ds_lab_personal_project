#pragma once
#include "base.h"
#include "food.h"

const string food_path = "data/food/";
const string food_extension = ".bin";
const string recipe_path = "data/recipe/";
const string recipe_extension = ".txt";

string get_recipy(const string& key);
void set_recipe_use_cin(const string& key);

food get_food(const string& key);
void set_food_use_cin(const string& key);
