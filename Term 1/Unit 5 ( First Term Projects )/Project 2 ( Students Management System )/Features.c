/*
 * Features.h
 *
 *  Created on: Jan 8, 2022
 *      Author: Aya Sayed
 */

#include "FIFO.h"
#include "Features.h"


uint8_t str[20];
uint32_t count = 0 , temp;

//Define Length
#define Student_buffer_length     5

FIFO_Buffer_t FIFO_Student;                         //define Student FIFO
Student_t Student_buffer[Student_buffer_length];    //define Student buffer is an array of structure
FILE* Student_File , *List;                         //pointer to file
Student_t New_Student;

//APIS to support features
Status_t Roll_Number_Searcher(uint32_t ID, uint32_t count)
{
	//Using Linear Search Algorithm
	for ( uint32_t i=0 ; i<count ; i++ )
	{
		if ( Student_buffer[i].Roll_Num == ID )
		{
			printf("[ERROR] This Roll Number %d is for another Student\n", ID);
			printf("[ERROR] Try another Roll Number\n");

			return ERROR;
		}
	}

	return NO_ERROR;
}

Status_t View_Student(Student_t* FIFO_buf)
{
	printf("Student Roll Number: %d\n", FIFO_buf->Roll_Num );
	printf("Student Name: %s %s\n", FIFO_buf->F_name , FIFO_buf->L_name );
	printf("Student GPA: %f\n", FIFO_buf->GPA );
	for ( uint32_t i=0 ; i<4 ; i++ )
		printf("Student Courses ID are: %d\n", FIFO_buf->Course_ID[i] );

	return DONE;
}




//Features APIS
Status_t Add_Student_From_File()
{
	//Read file using fopen() function
	Student_File = fopen( "Students_File.txt" , "r" );

	//Check if fopen() successfully done or not
	if ( Student_File == NULL )
	{
		printf("[ERROR] Student_File.txt file isn't found \n");
		printf("[ERROR] adding students from file failed. \n");
		return ERROR;
    }

	//Until The Student_File.txt file end
    while ( !feof(Student_File) )
    {
    	//Reading Roll Number of The Student
    	fscanf( Student_File , "%d" , &New_Student.Roll_Num );

    	if ( Roll_Number_Searcher( New_Student.Roll_Num , count ) == ERROR )
    	{
    		//Ignore that line
    		fscanf(Student_File, "%*[^\n]");
    		continue;
    	}

    	//Reading Name of The Student
    	fscanf( Student_File , "%s" , New_Student.F_name );
    	fscanf( Student_File , "%s" , New_Student.L_name );

    	//Reading GPA of The Student
    	fscanf( Student_File , "%f" , &New_Student.GPA );

    	//Reading Registered Courses of The Student
    	for ( uint32_t i = 0 ; i<4 ; i++)
    	{
    		fscanf( Student_File , "%d" , &New_Student.Course_ID[i] );
    	}

    	//Enqueue each Student in the FIFO
    	//FIFO Initialization
    	if ( count == 0 )
    		if ( FIFO_INIT( &FIFO_Student , Student_buffer , Student_buffer_length ) == FIFO_NO_ERROR )
    			printf("[NO_ERROR] FIFO Student Initialization is Done\n");


    	//padding FIFO UART Buffer by its values
		if ( FIFO_Enqueue( &FIFO_Student , New_Student ) == FIFO_NO_ERROR )
			printf("[NO ERROR] FIFO NO ERROR in Enqueue \n");
		else
		{
			printf("[ERROR] FIFO ERROR in Eequeue\n");
			return ERROR;
		}

		//count the length
		count++;
    }

	printf("Students details are saved successfully\n");

	//Close the file
	fclose(Student_File);

	printf("[DONE]\n");
	return DONE;
}

Status_t Add_Student_Manually()
{
	//FIFO Initialization
	if ( count == 0 )
		if ( FIFO_INIT( &FIFO_Student , Student_buffer , Student_buffer_length ) == FIFO_NO_ERROR )
			printf("[NO_ERROR] FIFO Student Initialization is Done\n");

	//////////////////////////////////////////////////////////
	//Read Student details Manually
	//read Student Roll Number
	printf("Student Roll Number: ");
	scanf( "%d" , &temp );

	//check if this roll number is unique or not
	if ( Roll_Number_Searcher( temp , count ) == ERROR )
		return ERROR;
	else
		New_Student.Roll_Num = temp;


	//read Student First Name
    printf("Student First Name: ");
    scanf( "%s", New_Student.F_name);


    //read Student Last Name
    printf("Student Last Name: ");
    scanf( "%s", New_Student.L_name);


    //read Student GPA
    printf("Student GPA: ");
    scanf( "%f" , &New_Student.GPA );

    //read Student Courses to be registered
	printf("C programming ID course is  1\n");
	printf("Embedded C ID course is     2\n");
	printf("Data Struture ID course is  3\n");
	printf("Micro-controller course is  4\n");
	printf("Interfacing ID course is    5\n");
	printf("Validation ID course is     6\n");
	printf("_____________________________\n");

	//setection Courses ID
	printf("Courses are \n");
	for ( uint32_t i=0 ; i<4 ; i++ )
	{
		printf("ID Course %d: ", i );
		scanf( "%d" , &New_Student.Course_ID[i] );
	}
	//////////////////////////////////////////////////////////

	//padding FIFO Student Buffer by its values
	if ( FIFO_Enqueue( &FIFO_Student , New_Student ) == FIFO_NO_ERROR )
		printf("[NO ERROR] FIFO NO ERROR in Enqueue \n");
	else
	{
		printf("[ERROR] FIFO ERROR in Eequeue\n");
		return ERROR;
	}

	//count the length
	count++;

	printf("[DONE]\n");
	return DONE;
}

Status_t Find_Student_Using_RollNumber()
{
	printf("Student Roll Number: ");
    scanf( "%d" , &temp );

    FIFO_Student.tail = Student_buffer;

	//Using Linear Search Algorithm
	for ( uint32_t i=0 ; i<FIFO_Student.count ; i++ )
	{
		if ( FIFO_Student.tail->Roll_Num == temp )
		{
			printf("This Roll Number %d is for Student: \n", temp);
			View_Student( Student_buffer+i );

			printf("[DONE]\n");
			return DONE;
		}
		FIFO_Student.tail++;
	}

	printf("This Roll Number isn't found  in the list\n");
	return NO_ERROR;
}

Status_t Find_Student_Using_FirstName()
{
	uint32_t Flag = 0;

	//read Student First Name
	printf("Student First Name: ");
	scanf( "%s" , str );

	FIFO_Student.tail = Student_buffer;

	//Using Linear Search Algorithm
	for ( uint32_t i=0 ; i<FIFO_Student.count ; i++ )
	{
		if ( stricmp( FIFO_Student.tail->F_name , str ) == 0 )
		{
			Flag = 1;
			printf("This Name is for Student\n");
			View_Student( Student_buffer+i );
		}
		FIFO_Student.tail++;
	}

    if (!Flag)
    	printf("This Name isn't found in the list\n");

    printf("[DONE]\n");
    return DONE;
}

Status_t Find_Student_Using_CourseID()
{
	uint32_t Flag = 0;

	//Read Course ID
	printf("ID Course: ");
	scanf( "%d" , &temp );

	FIFO_Student.tail = Student_buffer;

	for ( uint32_t i=0 ; i<FIFO_Student.count ; i++ )
	{
		printf("The Student who registered in %d are: \n", temp );
		for ( uint32_t j=0 ; j<4 ; j++ )
		{
			if ( Student_buffer[i].Course_ID[j] == temp )
			{
				Flag = 1;
				View_Student( Student_buffer+i );
			}
			FIFO_Student.tail++;
		}
	}

	if (!Flag)
		printf("no one registered this course\n");

	printf("[DONE]\n");
	return DONE;
}

Status_t Find_Length()
{
	printf("This list content %d Student\n", FIFO_Student.count );
	printf("[DONE]\n");
	return DONE;
}

Status_t Detete_Student()
{
	//check if FIFO Student isn't empty
	if ( FIFO_STATUS( &FIFO_Student ) == FIFO_EMPTY )
		return FIFO_EMPTY;

	//Read the roll number of student to delete
	printf("Student Roll Number: ");
	scanf( "%d" , &temp );

	FIFO_Student.tail = Student_buffer;

	//Using Linear Search Algorithm
	for ( uint32_t i = 0 ; i < FIFO_Student.count ; i++ )
	{
		if ( Student_buffer[i].Roll_Num == temp )
		{
			printf("This Roll Number %d is for Student: \n", temp);
			View_Student( Student_buffer + i );
			printf("Are you sure that you wanna delete him (Yes or No) ?\n");
			scanf( "%s" , str );

			//if you don't wanna delete him
			if ( stricmp( str , "No" ) == 0 )
				return DONE;

			Student_buffer[i] = *(FIFO_Student.tail);

			//Circular FIFO
			if( FIFO_Student.tail == FIFO_Student.Base )
			{
				FIFO_Student.tail++;
				FIFO_Student.Base = FIFO_Student.tail;
			}

			FIFO_Student.count--;

			printf("[DONE]\n");
			return DONE;
		}

		FIFO_Student.tail++;
	}

	printf("This Roll Number isn't found  in the list\n");

	return DONE;
}

Status_t View_Students()
{
	FIFO_Student.tail = Student_buffer;
	for ( uint32_t i = 0; i < FIFO_Student.count; i++ )
	{
		//check if FIFO buffer is exist
		if (( FIFO_STATUS(&FIFO_Student) != FIFO_EMPTY ) || (FIFO_STATUS(&FIFO_Student) != FIFO_NULL) )
		{
			View_Student(FIFO_Student.tail);
			FIFO_Student.tail++;
		}
		else
		{
			printf("FIFO Student is Empty\n");
			return FIFO_EMPTY;
		}
	}

	printf("[DONE]\n");
	return DONE;
}

Status_t Update_Student()
{
	printf("Student Roll Number: ");
	scanf( "%d" , &temp );

	FIFO_Student.tail = Student_buffer;

	//Using Linear Search Algorithm
	for ( uint32_t i=0 ; i<FIFO_Student.count ; i++ )
	{
		if ( FIFO_Student.tail->Roll_Num == temp )
		{
			printf("This Roll Number %d is for Student: \n", temp);
			View_Student( Student_buffer + i );

			//Switching on the updates
			printf("For update Student name select 1\n");
			printf("For update roll number select 2\n");
			printf("For update Student GPA select 3\n");
			printf("For update courses ID select 4\n");

			scanf( "%d" , &temp );

			switch(temp){
			case 1:
			{
				//read Student First Name
				printf("Student First Name: ");
				scanf( "%s" , str );
				strcpy( FIFO_Student.tail->F_name , str );

				//read Student First Name
				printf("Student Last Name: ");
				scanf( "%s" , str );
				strcpy( FIFO_Student.tail->L_name , str );

				printf("[DONE]\n");
				return DONE;
			}
			case 2:
			{
				//read Student Roll Number
				printf("Student Roll Number: ");
				scanf( "%d" , &temp );
				FIFO_Student.tail->Roll_Num = temp;

				printf("[DONE]\n");
				return DONE;
			}
			case 3:
			{
				//read Student GPA
				printf("Student GPA: ");
				scanf( "%d" , &temp );
				FIFO_Student.tail->GPA = temp;

				printf("[DONE]\n");
				return DONE;
			}
			case 4:
			{
				//read Student Courses to be registered
				printf("C programming ID course is  1\n");
				printf("Embedded C ID course is     2\n");
				printf("Data Struture ID course is  3\n");
				printf("Micro-controller course is  4\n");
				printf("Interfacing ID course is    5\n");
				printf("Validation ID course is     6\n");
				printf("_____________________________\n");

				//setection Courses ID
				printf("Courses are \n");
				for ( uint32_t i=0 ; i<4 ; i++ )
				{
					printf("ID Course %d: ", i );
					scanf( "%d" , &temp );
					FIFO_Student.tail->Course_ID[i] = temp;
				}

                printf("[DONE]\n");
				return DONE;
			}
			}
		}
		FIFO_Student.tail++;
	}

	printf("This Roll Number isn't found  in the list\n");

	return DONE;
}

Status_t Save_to_File()
{
	//Write file using fopen() function
	List = fopen( "Students_File.txt" , "w" );

	//Check if fopen() successfully done or not
	if ( List == NULL )
	{
		printf("[ERROR] Student_File.txt file isn't found \n");
		printf("[ERROR] adding students from file failed. \n");
		return ERROR;
	}

	FIFO_Student.tail = Student_buffer;

	//Until Student FIFO end
	for ( uint32_t i=0 ; i<FIFO_Student.count ; i++ )
	{
		//Write Student details
		fprintf( List , "%d " , FIFO_Student.tail->Roll_Num );
		fprintf( List , "%s " , FIFO_Student.tail->F_name );
		fprintf( List , "%s " , FIFO_Student.tail->L_name );
		fprintf( List , "%f " , FIFO_Student.tail->GPA );

		for ( uint32_t i=0 ; i<FIFO_Student.count ; i++ )
		{
			fprintf( List , "%d " , FIFO_Student.tail->Course_ID[i] );
		}
		fprintf( List ,"\n");

		FIFO_Student.tail++;
	}
	printf("Students details are saved successfully\n");

	//Close the file
	fclose(List);

	return DONE;
}
