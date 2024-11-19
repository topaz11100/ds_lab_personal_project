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
		
		input_to_vector(cin, menu);
		if (menu[0] == "end")
		{
			program_off();
			break;
		}
		else
		{
			r.push(get_food(menu[0]));
			r.print();
		}
	}

	clock_t.join();
	second_work_t.join();
	reminder_work_t.join();
	alert_work_t.join();

	return 0;
}

