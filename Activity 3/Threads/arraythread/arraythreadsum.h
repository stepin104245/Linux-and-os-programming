#ifndef ARRAYTHREADSUM_H
#define ARRAYTHREADSUM_H

#include<pthread.h>
#include<stdio.h>
void* task_body(void* pv);
int arr[1000];
int sum[10];
int final_sum;
#endif
