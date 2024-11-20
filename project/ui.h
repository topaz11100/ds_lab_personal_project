#pragma once

#include "base.h"
#include "food.h"
#include "refrigerator.h"
#include "file_manage.h"
#include "Time.h"

void input_to_vector(istream& in, vector<string>& v);

void menu_promft();
/*
{
	cout << "냉장고 메뉴 선택\n";
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
*/

void print_all_food(refrigerator& r);

void push_food(refrigerator& r);

void pop_food(refrigerator& r);

void print_recipe();

void save_food();

void save_recipe();

void print_5_food(refrigerator& r);

void program_off();
