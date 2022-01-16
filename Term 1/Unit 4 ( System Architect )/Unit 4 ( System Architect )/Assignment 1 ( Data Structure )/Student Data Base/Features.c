/*
 * Features.c
 *
 *  Created on: Jan 15, 2022
 *      Author: Aya Sayed
 */

#include "Features.h"

//global pointers
Student_t* p_NewStudent     = NULL ;
Student_t* p_FirstStudent   = NULL ;
Student_t* p_LastStudent    = NULL ;
Student_t* p_PrevStudent    = NULL ;
Student_t* p_CurrentStudent = NULL ;
Student_t* p_NextStudent    = NULL ;

//global variables
uint8_t temp[20] ;
uint32_t length ;

//APIS
//APIS to support features
int Get_length(struct Student* ptr )
{
	if (ptr)
	{
		return 1 + Get_length(ptr->gp_next_student);
	}
	else
		return 0;
}

Status Fill_Student(struct Student* ptr)
{
	//fill student data
	Dprint("Enter Student Data: ");

	Dprint("\n\t Student ID: ");
	Gets(temp);
	p_NewStudent->_Data.ID = atoi (temp);

	Dprint("\t Student Name: ");
	Gets(p_NewStudent->_Data.Name);

	Dprint("\t Student Height: ");
	Gets(temp);
	p_NewStudent->_Data.Height = atof (temp);

	Dprint("_________________________________  \n");

	return DONE ;
}

//features
Status Add_Student()
{
	//allocate new record in the heap
	p_NewStudent = (Student_t*) malloc(sizeof(Student_t));
	//check if malloc() isn't succeeded
	if (!p_NewStudent)
	{
		Dprint("error");
		return ERROR ;
	}

	//list is empty
	if (!p_FirstStudent)
		p_FirstStudent = p_NewStudent;
	else //list isn't empty
	{
		//Navigate last student
		p_LastStudent = p_FirstStudent;
		while(p_LastStudent->gp_next_student)
			p_LastStudent = p_LastStudent->gp_next_student;

		p_LastStudent->gp_next_student = p_NewStudent;
    }
	p_LastStudent = p_NewStudent;

	//fill student data
	Fill_Student(p_NewStudent);

	//set global pointer to next student NULL
	p_NewStudent->gp_next_student = NULL;

	//increase length
	length++;

	return NO_ERROR ;
}

Status Delete_Student()
{
	Dprint("Enter his ID: \n");
	Gets(temp);

	//set direction pointers
	p_CurrentStudent = p_FirstStudent ;

	//while list isn't empty
	if (p_FirstStudent)
	{
		//search for ID student to delete
		//if student is the first one
		if (p_FirstStudent->_Data.ID == atoi(temp))
		{
			p_FirstStudent = p_FirstStudent->gp_next_student ;
			free (p_CurrentStudent->gp_next_student);
		}
		else {
			//if student in any location else
			while (p_CurrentStudent->_Data.ID != atoi(temp)) {
				if (!p_CurrentStudent->gp_next_student) {
					Dprint("This ID not found\n");
					Dprint("_________________________________  \n");
					return ERROR;
				}
				p_PrevStudent = p_CurrentStudent;
				p_CurrentStudent = p_CurrentStudent->gp_next_student;
			}
			//if this element is the last
			if (!p_CurrentStudent->gp_next_student)
				p_PrevStudent->gp_next_student = NULL;
			else {
				p_PrevStudent->gp_next_student =
						p_CurrentStudent->gp_next_student;
				free(p_CurrentStudent->gp_next_student);
			}
		}
	}

	//decrease length
	length--;

	//list is empty
    if (p_FirstStudent == NULL)
    	Dprint("list is empty\n");

    Dprint("_________________________________  \n");
    return NO_ERROR ;
}

Status View_Students()
{
	uint32_t count = 0 ;
	//set direction pointer
	p_CurrentStudent = p_FirstStudent;

	//list is empty
	if (p_FirstStudent == NULL)
	{
		Dprint("list is empty\n");
		Dprint("_________________________________  \n");
		return EMPTY;
	}

	//while list isn't empty
	Dprint("Students are\n");
	while (p_CurrentStudent)
	{
		Dprint("Record number %d\n",count+1);
		Dprint("\tID    : %d\n",p_CurrentStudent->_Data.ID);
		Dprint("\tName  : %s\n",p_CurrentStudent->_Data.Name);
		Dprint("\tHeight: %f\n",p_CurrentStudent->_Data.Height);

		//Go to next student
		p_CurrentStudent = p_CurrentStudent->gp_next_student;
		count++;
	}
	Dprint("_________________________________  \n");
	return DONE ;
}

Status Delete_All()
{
	//list is empty
	if (!p_FirstStudent)
	{
		Dprint("list is empty");
		Dprint("_________________________________  \n");
		return EMPTY ;
	}
	else//list isn't empty
	{
		p_CurrentStudent = p_FirstStudent;
		while(p_CurrentStudent)
		{
			p_CurrentStudent = p_FirstStudent->gp_next_student;
		    free (p_FirstStudent->gp_next_student);
		    p_FirstStudent = p_CurrentStudent;
		}
		Dprint("Done list is empty now\n");
		Dprint("_________________________________  \n");

		//set length by 0
		length = 0;
		return DONE ;
	}
}

Status Get_Nth_Node_first()
{
	//get index of student to view
	Dprint("Enter his index(first): \n");
	Gets(temp);

	uint32_t count = 0;
	//list is empty
	if (p_FirstStudent == NULL)
	{
		Dprint("list is empty\n");
		Dprint("_________________________________  \n");
		return EMPTY;
	}

	//check if that index exists or not
	if (atoi(temp) > length-1)
	{
		Dprint("This index not found\n");
		Dprint("_________________________________  \n");
		return DONE;
	}

	//set direction pointer
	p_CurrentStudent = p_FirstStudent;
	while (atoi(temp) != count)
	{
		//Go to next student
		p_CurrentStudent = p_CurrentStudent->gp_next_student;
		count++;
	}
	Dprint("Record Student of index %d\n",atoi(temp));
	Dprint("\tID    : %d\n",p_CurrentStudent->_Data.ID);
	Dprint("\tName  : %s\n",p_CurrentStudent->_Data.Name);
	Dprint("\tHeight: %f\n",p_CurrentStudent->_Data.Height);
	Dprint("_________________________________  \n");
	return DONE ;
}

Status Get_Nth_Node_end()
{
	//get index of student to view
	Dprint("Enter his index(end): \n");
	Gets(temp);

	uint32_t count = 0;
	//list is empty
	if (p_FirstStudent == NULL) {
		Dprint("list is empty\n");
		Dprint("_________________________________  \n");
		return EMPTY;
	}

	//check if that index exists or not
	if (atoi(temp) > length) {
		Dprint("This index not found\n");
		Dprint("_________________________________  \n");
		return DONE;
	}

	//set direction pointer
	p_CurrentStudent = p_FirstStudent;
	while (atoi(temp) != (length-count))
	{
		//Go to next student
		p_CurrentStudent = p_CurrentStudent->gp_next_student;
		count++;
	}

	Dprint("Record Student of index %d\n", atoi(temp));
	Dprint("\tID    : %d\n", p_CurrentStudent->_Data.ID);
	Dprint("\tName  : %s\n", p_CurrentStudent->_Data.Name);
	Dprint("\tHeight: %f\n", p_CurrentStudent->_Data.Height);
	Dprint("_________________________________  \n");

	return DONE;
}

Status Find_Length()
{
	if (p_FirstStudent)
	{
		//switch between iterative or recursive method
		//switch 1 for iterative
		//switch 2 for recursive
		Dprint("switch 1 for iterative\n");
		Dprint("switch 2 for recursive\n");
		Dprint("enter an option: ");
		Gets(temp);
		switch(atoi(temp))
		{
		//using iterative method
		case 1:
			Dprint("length is %d\n", length);
			Dprint("_________________________________  \n");
			break;

		//using recursive method
		case 2:
			length = Get_length(p_FirstStudent);
			Dprint("length is %d\n", length);
			Dprint("_________________________________  \n");
			break;
		}
	}
	else
	{
		Dprint("list is empty\n");
		Dprint("_________________________________  \n");
		return EMPTY ;
	}
	return DONE ;
}

Status Find_Middle()
{
	uint32_t mid = floor((length / 2));
	uint32_t count = 0;

	//set direction pointer
	p_CurrentStudent = p_FirstStudent;
	while (mid != count)
	{
		//Go to next student
		p_CurrentStudent = p_CurrentStudent->gp_next_student;
		count++;
	}
	Dprint("Record Student of index %d\n", count);
	Dprint("\tID    : %d\n", p_CurrentStudent->_Data.ID);
	Dprint("\tName  : %s\n", p_CurrentStudent->_Data.Name);
	Dprint("\tHeight: %f\n", p_CurrentStudent->_Data.Height);
	Dprint("_________________________________  \n");

	return DONE ;
}

Status Detect_loop()
{
	Student_t* p_fast = p_FirstStudent;
	Student_t* p_slow = p_FirstStudent;

	//untill linked list isn't reach to its end and isn't empty
	while (p_fast && p_slow && p_fast->gp_next_student)
	{
		p_slow = p_slow->gp_next_student;
		p_fast = p_fast->gp_next_student->gp_next_student; //pointer to pointer to element
		//check or detect loop
		if (p_fast == p_slow)
		{
			Dprint("there is a loop here");
			Dprint("\tID    : %d\n", p_fast->_Data.ID);
			Dprint("\tName  : %s\n", p_fast->_Data.Name);
			Dprint("\tHeight: %f\n", p_fast->_Data.Height);
			Dprint("_________________________________  \n");

			return DONE ;
		}
	}
	Dprint("there isn't a loop here\n");
	Dprint("_________________________________  \n");
	return DONE ;
}

Status Reverse()
{
	//set direction
	p_PrevStudent = NULL;
	p_CurrentStudent = p_FirstStudent;
	p_NextStudent = p_CurrentStudent->gp_next_student;
	while (p_CurrentStudent)
	{
		//for first element do this
		if (p_CurrentStudent == p_FirstStudent)
			p_LastStudent = p_FirstStudent;

		//set direction
		p_NextStudent = p_CurrentStudent->gp_next_student;
		p_CurrentStudent->gp_next_student = p_PrevStudent;
		p_PrevStudent = p_CurrentStudent;
		p_CurrentStudent = p_NextStudent;

	}
	//for last element do this
	p_FirstStudent = p_PrevStudent;
	//to check my algorithm
	View_Students();

	return NO_ERROR;
}

