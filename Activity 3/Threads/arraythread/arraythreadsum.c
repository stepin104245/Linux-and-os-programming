#include"arraythreadsum.h"
void* task_body(void* pv)
{
	int i,thread_val=(int)pv,temp;
	for(i=1;i<=100;i++)
		sum[thread_val]=arr[thread_val*100+i];
	//pthread_exit((void*)temp);
}
int main()
{
	int i,n=10;
    for(i=0;i<1000;i++){
        arr[i]=i;
    }
	pthread_t ptarr[n];
	for(i=0;i<10;i++)
	{
	  pthread_create(&ptarr[i],NULL,task_body,(void*)i);
	}
	for(i=0;i<n;i++)
	  pthread_join(ptarr[i],NULL);
    for(i=0;i<n;i++)
      final_sum+=sum[i];
        
	printf("Final sum=%d",final_sum);
	return 0;	//exit(0);
}
