#include<stdio.h>
#include<omp.h>
#include<sys/time.h>
#include<stdlib.h>
struct timeval  TimeValue_Start;
    struct timezone TimeZone_Start;

    struct timeval  TimeValue_Final;
    struct timezone TimeZone_Final;
    long   time_start, time_end;
     double  time_overhead;
void bdss(int a[],int n);
void main(){
int a[100],n,i;
printf("enter the number of elements:");
scanf("%d",&n);
//printf("enter the elements:");
for(i=1;i<=n;i++){
	//scanf("%d",&a[i]);
	a[i]=rand()%1000;
}
bdss(a,n);
}

void bdss(int a[],int n){
int i,j,min,max,temp;
 gettimeofday(&TimeValue_Start, &TimeZone_Start);
#pragma omp parallel for private(i,j) schedule(guided,4)
for(i=1;i<=n/2;i++){
	min=i;
	max=i;
	for(j=i+1;j<=n-i+1;j++){
		if(a[j]<a[min])min=j;
		if(a[j]>a[max])max=j;
		}
	if(min!=i&&max!=n-i+1){
		if(min==n-i+1&&max==i){
		temp=a[min];
		a[min]=a[max];
		a[max]=temp;
		}
		else if(min==n-i+1){
		temp=a[i];
		a[i]=a[min];
		a[min]=a[max];
		a[max]=temp;
		}
		else if(max==i){
		temp=a[i];
		a[i]=a[min];
		a[min]=a[n-i+1];
		a[n-i+1]=temp;
		}
		else{
		temp=a[i];
		a[i]=a[min];
		a[min]=a[n-i+1];
		a[n-i+1]=a[max];
		a[max]=temp;
		}
	       }
	else if(min==i&&max!=n-i+1){
	temp=a[n-i+1];
	a[n-i+1]=a[max];
	a[max]=temp;
	}
	else if(min!=i&&max==n-i+1){
	temp=a[i];
	a[i]=a[min];
	a[min]=temp;
	}
   }
gettimeofday(&TimeValue_Final, &TimeZone_Final);
for(i=1;i<=n;i++){
printf("%d\t",a[i]);
}
time_start = TimeValue_Start.tv_sec * 1000000 + TimeValue_Start.tv_usec;
time_end = TimeValue_Final.tv_sec * 1000000 + TimeValue_Final.tv_usec;
    time_overhead = (time_end - time_start)/1000000.0;
printf("\n\nTime in Seconds (T)         : %lf\n",time_overhead);

}
