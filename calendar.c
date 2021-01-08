#ifndef __K612_GROCERIES_CALENDAR__
#define __K612_GROCERIES_CALENDAR__
#endif
#include <stdio.h>
const char * Weekdays[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
char * GetWeekdays(int Year, int Month, int Day) {
	// This function returns weekdays in string.
	// @Arguments: Year: YYYY, Month: M/MM and Day: D/DD.
	int m = (Month <= 2) ? Month + 12 : Month;
	int y = (m > 12) ? Year - 1 : Year;
	return Weekdays[(Day + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400)]; // Using the formula. w=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400
}
