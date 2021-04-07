//
// Created by Александр on 06.12.2019.
//


#ifndef C_LIBRARY_H
#define C_LIBRARY_H

#include <stdint.h>
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include <stdio.h>


void Extract(char* arcname);

void List(char* arcname);

void Create(char* arc_name, int filecount, char* files[]);




#endif //C_LIBRARY_H
