/* Name: Grim, Evan */
/* EID: grimet */
/* Section: N/A */
/* Assignment: 2 */
/* Purpose: A program that performs useful calculations for someone travelling to South Africa */

#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef unsigned char Bool;

int main()
{
	Bool keep_running = TRUE;

	printf("SATT (South African Traveler Tool)\n");
	printf("\n");

	while (keep_running == TRUE)
	{
		// Menu variable(s)
		int menu_choice;

		// Time variable(s)
		int hour_input, hour_output;
		int minute;

		// Money variable(s)
		int dollar, cents;
		float zar;

		// Temperature variable(s)
		int temp_f;
		float temp_c;

		printf("Menu\n");
		printf("------------------------------------------------------\n");
		printf("1.   Convert a given Austin time to Cape Town time\n");
		printf("2.   Convert a given Cape Town time to Austin time\n");
		printf("3.   Convert a given USD value to ZAR\n");
		printf("4.   Convert a given ZAR value to USD value\n");
		printf("5.   Convert a given Fahrenheit temperature to Celsius\n");
		printf("6.   Convert a given Celsius temperature to Fahrenheit\n");
		printf("7.   Convert a given volume in L to gallons, fl ounces\n");
		printf("8.   Convert a given volume in gallons, fl ounces to L\n");
		printf("9.   Convert a given distance in km to miles\n");
		printf("10.  Convert a given distance in miles to km\n");
		printf("11.  Stop doing conversions and quit the program\n");
		printf("------------------------------------------------------\n");
		printf("Enter a number from the menu (1-11) to select a specific conversion or quit: ");
		scanf("%d", &menu_choice);

		switch(menu_choice)
		{
			case 1: // Time: CDT -> SAST
				break;
			case 2: // Time: SAST -> CDT
				printf("Enter a South African time to be converted (in hours and minutes): ");
				scanf("%d %d", &hour_input, &minute);
//				hour_output = hour_input - DELTA_FROM_CDT_TO_SAST;

				break;
			case 3: // Money: USD -> ZAR
				break;
			case 4: // Money: ZAR -> USD
				break;
			case 5: // Temperature: F -> C
				break;
			case 6: // Temperature: C -> F
				break;
			case 7: // Volume: L -> gal/fl.oz

				break;
			case 8: // Volume: gal/fl.oz -> L
				break;
			case 9: // Distance: km -> miles
				break;
			case 10:// Distance: miles -> km
				break;
			case 11:// Exit
				printf("Good Bye\n");
				keep_running = FALSE;
				break;
			default:
				printf("Error: Unrecognized menu selection");
		}
	}

	return 0;
}
