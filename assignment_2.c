/* Name: Grim, Evan */
/* EID: grimet */
/* Section: N/A */
/* Assignment: 2 */
/* Purpose: A program that performs useful calculations for someone traveling
 *          to South Africa */

#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define CDT_TO_SAST_OFFSET 7

#define USD_PER_ZAR 0.137011
#define ZAR_PER_USD 7.29869
#define DOLLARS_PER_CENT .01
#define CENTS_PER_DOLLAR_INT 100

#define C_TO_F_SCALAR (9.0/5.0)
#define F_TO_C_SCALAR (5.0/9.0)
#define F_TO_C_OFFSET 32

#define OZ_PER_L 33.8140227
#define OZ_PER_GALLON_INT 128

#define MILES_PER_KM .6213712
#define KM_PER_MILE 1.609355

typedef unsigned char Bool;

/* Normally a main function should not be this long, but instead would break
 * the process up into smaller blocks implemented in individual functions.
 * However, since we hadn't formally introduced functions at the time of this
 * assignment I went ahead and implemented it all without using separate
 * functions.  Kudos to those of you who submitted a solution using functions,
 * as this is generally better style.
 */
int main()
{
	Bool keep_running = TRUE;

	printf("Austonian in South Africa Tool (ASAT)\n");

	while (keep_running == TRUE)
	{
		// Menu variable(s)
		int menu_choice;

		// Time variable(s)
		int hour_input, hour_output;
		int minute;
		Bool different_day;

		// Money variable(s)
		int dollars, cents;
		float usd, zar;

		// Temperature variable(s)
		float celsius;
		int fahrenheit;

		// Volume variable(s)
		float liters, ounces;
		int gallons;

		// Distance variable(s)
		float km, miles;

		printf("\n\n"); // print whitespace to make the output more readable
		printf("------------------------------------------------------\n");
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
		printf("\n");

		switch(menu_choice)
		{
			case 1: // Time: CDT -> SAST
				/* Prompt for input */
				printf("Enter an Austin time to be converted (in hours and minutes): ");
				scanf("%d %d", &hour_input, &minute);

				/* Perform conversion */
				hour_output = hour_input + CDT_TO_SAST_OFFSET;

				// Correct hour if rolled over to next day
				if (hour_output > 23)
				{
					hour_output -= 24;
					different_day = TRUE;
				}
				else
					different_day = FALSE;

				/* Print output */
				printf("The equivalent time in South Africa is: %.2d %.2d",
						hour_output, minute);

				// Add day change notice if appropriate
				if (different_day == TRUE)
				{
					printf(" (the day after)");
				}

				printf("\n");
				break;

			case 2: // Time: SAST -> CDT
				/* Prompt for input */
				printf("Enter a South African time to be converted (in hours and minutes): ");
				scanf("%d %d", &hour_input, &minute);

				/* Perform conversion */
				hour_output = hour_input - CDT_TO_SAST_OFFSET;

				// Correct hour if rolled back to next day
				if (hour_output < 0)
				{
					hour_output += 24;
					different_day = TRUE;
				}
				else
				{
					different_day = FALSE;
				}

				/* Print output */
				printf("The equivalent time in Austin is: %.2d %.2d",
						hour_output, minute);

				// Add day change notice if appropriate
				if (different_day == TRUE)
				{
					printf(" (the day before)");
				}

				printf("\n");
				break;

			case 3: // Money: USD -> ZAR
				/* Prompt for input */
				printf("Enter a US currency amount to be converted (in dollars and cents): ");
				scanf("%d %d", &dollars, &cents);

				/* Perform conversion */
				usd = dollars + cents*DOLLARS_PER_CENT;
				zar = usd * ZAR_PER_USD;

				/* Print output (let printf do the rounding) */
				printf("The equivalent currency amount in ZAR is: %.2f\n", zar);
				break;

			case 4: // Money: ZAR -> USD
				/* Prompt for input */
				printf("Enter a South African currency amount to be converted (in ZAR): ");
				scanf("%f", &zar);

				/* Perform conversion */

				// Convert ZAR to cents (add .5  and truncate to round)
				cents = (int)(zar * USD_PER_ZAR * CENTS_PER_DOLLAR_INT + .5);

				// Pull out the dollar amount and adjust value of cents
				dollars = cents / CENTS_PER_DOLLAR_INT;
				cents = cents % CENTS_PER_DOLLAR_INT;

				/* Print output */
				printf("The equivalent currency amount in USD (dollars and cents) is: %.2d %.2d\n", dollars, cents);
				break;

			case 5: // Temperature: F -> C
				/* Prompt for input */
				printf("Enter a US temperature to be converted (in  Fahrenheit): ");
				scanf("%d", &fahrenheit);

				/* Perform conversion */
				celsius = F_TO_C_SCALAR * (fahrenheit - F_TO_C_OFFSET);

				/* Print output (rounding to 2 decimal place digits not required by assignment) */
				printf("The equivalent temperature in Celsius is: %.2f\n", celsius);
				break;

			case 6: // Temperature: C -> F
				/* Prompt for input */
				printf("Enter a South African temperature to be converted (in Celsius): ");
				scanf("%f", &celsius);

				/* Perform conversion */

				// Convert C to F (add .5 and truncate to round)
				fahrenheit = (int)((C_TO_F_SCALAR * celsius) + F_TO_C_OFFSET + .5);

				/* Print output */
				printf("The equivalent temperature in Fahrenheit (rounded) is: %d\n", fahrenheit);
				break;

			case 7: // Volume: L -> gal/fl.oz
				/* Prompt for input */
				printf("Enter a South African volume to be converted (in liters): ");
				scanf("%f", &liters);

				/* Perform conversion */

				// Convert L to fluid ounces
				ounces = liters * OZ_PER_L;

				// Round to 3 digit precision by:
				//	* mult by 1000
				//  * add .5
				//  * truncate
				//  * divide by 1000.0 (ensures floating point division)
				ounces = ((int)(ounces * 1000 + .5))/1000.0;

				// Pull out number of gallons and adjust value of ounces
				gallons = ((int) ounces) / OZ_PER_GALLON_INT;
				ounces = ounces - gallons * OZ_PER_GALLON_INT;


				/* Print output */
				printf("The equivalent volume in gallons and fluid ounces is: %d %.3f\n", gallons, ounces);
				break;

			case 8: // Volume: gal/fl.oz -> L
				/* Prompt for input */
				printf("Enter an Austin volume to be converted (in gallons and fluid ounces): ");
				scanf("%d %f", &gallons, &ounces);

				/* Perform conversion */
				liters = (gallons * OZ_PER_GALLON_INT + ounces) / OZ_PER_L;

				/* Print output (rounding to 3 decimal place digits not required by assignment) */
				printf("The equivalent volume in liters is: %.3f\n", liters);
				break;

			case 9: // Distance: km -> miles
				/* Prompt for input */
				printf("Enter a South African distance to be converted (in km): ");
				scanf("%f", &km);

				/* Perform conversion */
				miles = km * MILES_PER_KM;

				/* Print output (rounding to 3 decimal place digits not required by assignment) */
				printf("The equivalent distance in miles is: %.3f\n", miles);
				break;

			case 10:// Distance: miles -> km
				/* Prompt for input */
				printf("Enter an Austin distance to be converted (in miles): ");
				scanf("%f", &miles);

				/* Perform conversion */
				km = miles * KM_PER_MILE;

				/* Print output (rounding to 3 decimal place digits not required by assignment) */
				printf("The equivalent distance in km is: %.3f\n", km);
				break;

			case 11:// Exit
				printf("Good Bye\n");
				keep_running = FALSE;
				break;

			default:
				printf("Error: Unrecognized menu selection");
		}

		// Flush any unread input by reading until a newline character is seen
		while (getchar() != '\n');
	}

	// Pause program before exiting by using getchar()
	getchar();

	return 0;
}
