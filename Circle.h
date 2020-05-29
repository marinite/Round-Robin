#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

typedef struct _process
{
	int begin = 0;
	int duration = 0;
	int number = 0;
	struct _process* next = NULL;
	struct _process* prev = NULL;
}process;
typedef struct _circle
{
	process* head;
}circle;

circle* init();
void add(circle* rr, int ar_begin[], int ar_duraction[], int i);
//void del(circle* rr);
#endif