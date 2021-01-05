#ifndef MAXMINTHREAD_H
#define MAXMINTHREAD_H

#include<pthread.h>
#include<stdio.h>
int arr[1000];
int max;
int min=999;
void* task_body1(void* pv);
#endif

