/*
 * Features.h
 *
 *  Created on: Jan 15, 2022
 *      Author: Aya Sayed
 */

#ifndef FEATURES_H_
#define FEATURES_H_

#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"

//print macro
#define Dprint(...)    {fflush(stdout); \
	                   fflush(stdin); \
                       printf(__VA_ARGS__); \
                       fflush(stdout); \
                       fflush(stdin);}

//get macro
#define Gets(...)    {gets(__VA_ARGS__); \
                       fflush(stdout); \
                       fflush(stdin);}

//define typedef
struct SData {
	uint32_t ID ;
	uint8_t Name[20] ;
	float Height ;
};

//create a node
typedef struct Student {
	struct SData _Data;
	struct Student* gp_next_student;
}Student_t;

//Enumariation
typedef enum {
	DONE,
	ERROR,
	NO_ERROR,
	EMPTY
}Status;


//APIS
//APIS to support features
int Get_length(struct Student* ptr);
Status Fill_Student(struct Student* ptr);

//features
Status Add_Student();
Status Delete_Student();
Status View_Students();
Status Delete_All();
Status Get_Nth_Node_first();
Status Get_Nth_Node_end();
Status Find_Length();
Status Find_Middle();
Status Detect_loop();
Status Reverse();


#endif /* FEATURES_H_ */
