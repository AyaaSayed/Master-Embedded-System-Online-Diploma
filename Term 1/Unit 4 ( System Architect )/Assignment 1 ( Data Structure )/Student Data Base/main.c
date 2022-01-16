/*
 * main.c
 *
 *  Created on: Jan 15, 2022
 *      Author: Aya Sayed
 */

#include "Features.h"

int main()
{
	//print the available options
	Dprint("Choose an Option from list to do:  \n");
	Dprint("_________________________________  \n");
	Dprint("1 : Add student                   \n");
	Dprint("2 : Delete student                \n");
	Dprint("3 : view students                 \n");
	Dprint("4 : Delete all                    \n");
	Dprint("5 : Get Nth of node from the first\n");
	Dprint("6 : Get Nth of node from the end  \n");
	Dprint("7 : Find the length               \n");
	Dprint("8 : Find the middle               \n");
	Dprint("9 : Detect loop                   \n");
	Dprint("10: Reverse                       \n");
	Dprint("_________________________________  \n");

	uint8_t option_num[10];

	while (1)
	{
		Dprint("Enter an option: ");
		Gets(option_num);

		//switching an option
		switch (atoi(option_num)) {
		case 1:
			Add_Student();
			break;
		case 2:
			Delete_Student();
			break;
		case 3:
			View_Students();
			break;
		case 4:
			Delete_All();
			break;
		case 5:
			Get_Nth_Node_first();
			break;
		case 6:
			Get_Nth_Node_end();
			break;
		case 7:
			Find_Length();
			break;
		case 8:
			Find_Middle();
			break;
		case 9:
			Detect_loop();
			break;
		case 10:
			Reverse();
			break;
		default:
			Dprint("Wrong Option\n");
			break;
		}
	}
}
