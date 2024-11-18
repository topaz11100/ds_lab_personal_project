#pragma once

#include "base.h"
#include "refrigerator.h"

void flow_clock();

void second_work(refrigerator& r);

void alert_work(refrigerator& r);

void reminder_work(refrigerator& r);