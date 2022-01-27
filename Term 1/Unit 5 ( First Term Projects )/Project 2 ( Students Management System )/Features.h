/*
 * Features.h
 *
 *  Created on: Jan 23, 2022
 *      Author: diesel
 */

#ifndef FEATURES_H_
#define FEATURES_H_

#include "FIFO.h"
#include "stdio.h"
#include "stdint.h"
#include "string.h"

//Enumariation
typedef enum {
    DONE,
    ERROR,
    NO_ERROR,
    EMPTY
} Status_t;

//APIS
//APIS to support features
Status_t View_Student(Student_t* FIFO_buf);
Status_t Roll_Number_Searcher(uint32_t ID, uint32_t count);

//features
Status_t Add_Student_From_File();
Status_t Add_Student_Manually();
Status_t Find_Student_Using_RollNumber();
Status_t Find_Student_Using_FirstName();
Status_t Find_Student_Using_CourseID();
Status_t Find_Length();
Status_t Detete_Student();
Status_t View_Students();
Status_t Update_Student();
Status_t Save_to_File();

#endif /* FEATURES_H_ */
