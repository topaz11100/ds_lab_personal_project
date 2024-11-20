#include "ui.h"

int main() {
	
	
	refrigerator r;

	thread clock_t{ flow_clock };
	thread second_work_t{ second_work, ref(r) };
	thread reminder_work_t{ reminder_work, ref(r) };
	thread alert_work_t{ alert_work, ref(r) };

	vector<string> menu;
	while (true)
	{
		menu_promft();
		input_to_vector(cin, menu);
		if (menu[0] == "1")
		{
			print_all_food(r);
		}
		else if (menu[0] == "2")
		{
			push_food(r);
		}
		else if (menu[0] == "3")
		{
			pop_food(r);
		}
		else if (menu[0] == "4")
		{
			print_recipe();
		}
		else if (menu[0] == "5")
		{
			print_5_food(r);
		}
		else if (menu[0] == "6")
		{
			save_food();
		}
		else if (menu[0] == "7")
		{
			save_recipe();
		}
		else if (menu[0] == "8")
		{
			break;
		}
		else
		{
			cout << "잘못된 입력입니다 다시 입력하세요" << endl;
		}
	}

	program_off();

	clock_t.join();
	second_work_t.join();
	reminder_work_t.join();
	alert_work_t.join();
	



	return 0;
}

