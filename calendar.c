#ifndef __K612_GROCERIES_CALENDAR__
#define __K612_GROCERIES_CALENDAR__
#endif
#include <stdio.h>
#include <stdlib.h>

/**
 * @Author Sam Huang
 * @Version 0.1a
*/

// This function returns the weekday of a specific day.
// Comes from https://stackoverflow.com/questions/6054016/c-program-to-find-Day-of-week-given-date
int GetWeekdays(int Year, int Month, int Day) {
	return ((int [])                                         \
          {1,2,3,4,5,6,7})[           \
      (                                                            \
          Day                                                      \
        + ((153 * (Month + 12 * ((14 - Month) / 12) - 3) + 2) / 5) \
        + (365 * (Year + 4800 - ((14 - Month) / 12)))              \
        + ((Year + 4800 - ((14 - Month) / 12)) / 4)                \
        - ((Year + 4800 - ((14 - Month) / 12)) / 100)              \
        + ((Year + 4800 - ((14 - Month) / 12)) / 400)              \
        - 32045                                                    \
      ) % 7];
}

int IsLeapYear(int Year) {
	return ( (Year % 4 == 0) && (Year % 100 != 0) || (Year % 400 == 0) );
}

int Days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const char * Months[] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

int main(int argc, char ** argv) {
	if (argc < 3) {
		printf("Usage: ./calendar yyyy mm");
	} else {
		int Year = atoi(argv[1]), Month = atoi(argv[2]);
		printf("%s %d\nMon Tue Wed Thu Fri Sat Sun\n", Months[Month], Year);
		if (IsLeapYear(Year)) Days[2]++;
		int i = 1, t = GetWeekdays(Year,Month,i);
		while (t != 1) {
			if (i == 1)
				for (int j = 1; j < t; j++) 
					printf("%3s ", " ");
			printf("%3d ", i);
			if (t % 7 == 0) printf("\n");
			i++;
			if (t + 1 < 8)
				t++;
			else t = 1;
		}
		t = 1;
		for (; i <= Days[Month]; i++, t++) {
			if (t == 8) {
				t = 1;
				printf("\n");
			}
			printf("%3d ", i);
		}
	}
	return 0;
}
