/*
 * main.c
 *
 *  Created on: Jan 23, 2022
 *      Author: Aya Sayed
 */

#include "FIFO.h"
#include "Features.h"

int main() {
	uint32_t option_num , Flag = 1;

    //to avoid eclipse debug
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	while (Flag) {
		//print the available options
		printf("______________________________________________________\n");
		printf("Choose an Option from list to do:        \n");
		printf("_________________________________________\n");
		printf("1 : Add the student details from file    \n");
		printf("2 : Add the student details Manually     \n");
		printf("3 : Find the Student by given Roll number\n");
		printf("4 : Find the Student by given First name \n");
		printf("5 : Find the Student by registered course\n");
		printf("6 : Find the length                      \n");
		printf("7 : Delete student                       \n");
		printf("8 : Update student                       \n");
		printf("9 : View students                        \n");
		printf("10: Save the list and Exit               \n");
		printf("______________________________________________________\n");

		printf("Enter an option: ");
		scanf( "%d" , &option_num );

		//switching an option
		switch (option_num){
		case 1:
			Add_Student_From_File();
			break;
		case 2:
			Add_Student_Manually();
			break;
		case 3:
			Find_Student_Using_RollNumber();
			break;
		case 4:
			Find_Student_Using_FirstName();
			break;
		case 5:
			Find_Student_Using_CourseID();
			break;
		case 6:
			Find_Length();
			break;
		case 7:
			Detete_Student();
			break;
		case 8:
			Update_Student();
			break;
		case 9:
			View_Students();
			break;
		case 10:
			Save_to_File();
			Flag = 0;
			break;
		default:
			printf("Wrong Option\n");
			break;
		}
	}
}
