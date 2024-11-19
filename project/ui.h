#pragma once

#include "base.h"
#include "food.h"
#include "refrigerator.h"
#include "file_manage.h"
#include "Time.h"

void input_to_vector(istream& in, vector<string>& v);

void menu_promft();

void print_all_food(refrigerator& r);

void push_food(refrigerator& r);

void pop_food(refrigerator& r);

void print_recipe();

void save_recipe();

void print_5_food(refrigerator& r);

void program_off();