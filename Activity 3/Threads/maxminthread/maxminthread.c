#include<pthread.h>
#include<stdio.h>
int arr[1000];
int max;
int min=999;

void* task_body1(void* pv)
{
	
	int i,thread_val=(int)pv;
	int temp=arr[thread_val*100];
	for(i=0;i<100;i++){
		if(arr[thread_val*100+i]>temp)
		   temp=arr[thread_val*100+i];
	}
	if(max<temp)
	   max=temp;
	//pthread_exit((void*)temp);
}
void* task_body2(void* pv)
{      
	int i,val=(int)pv;
	int tem=arr[val*100];
	for(i=0;i<100;i++){
		if(arr[val*100+i]<tem)
		  tem=arr[val*100+i];
	}
	if(min>tem)
	   min=tem; 
	
}
int main()
{
	int i,n=10;
    for(i=0;i<1000;i++){
        arr[i]=i+1;
    }
	pthread_t ptarr1[n];
	pthread_t ptarr2[n];
	for(i=0;i<10;i++)
	{
	  pthread_create(&ptarr1[i],NULL,task_body1,(void*)i);
	   pthread_create(&ptarr2[i],NULL,task_body2,(void*)i);
	}
	for(i=0;i<n;i++){
      pthread_join(ptarr1[i],NULL);
	  pthread_join(ptarr2[i],NULL);
	}  
	printf("max=%d , min = %d",max,min);
	return 0;	//exit(0);
}

