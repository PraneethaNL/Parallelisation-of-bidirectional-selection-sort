#include<stdio.h>
#include<sys/time.h>
#include<stdlib.h>
void bdss(int a[],int n);
struct timeval  TimeValue_Start;
    struct timezone TimeZone_Start;

    struct timeval  TimeValue_Final;
    struct timezone TimeZone_Final;
    long   time_start, time_end;
     double  time_overhead;
void main(){
int a[100],n,i;
printf("enter the number of elements:");
scanf("%d",&n);
printf("enter the elements:");
for(i=1;i<=n;i++){
	scanf("%d",&a[i]);
}
bdss(a,n);
}

void bdss(int a[],int n){
 int i,j, min, max,temp;
  gettimeofday(&TimeValue_Start, &TimeZone_Start);
for(i=1; i<=n/2; i++)
{
	 for(j=i;j<=n/2;j++)
		if(a[j]>a[n-j+1]){
			temp=a[j];
			a[j]=a[n-j+1]; 
			a[n-j+1]=temp; }
	min=i;
	max=n-i+1 ; 
	for(j=i+ 1 ;j<=(n+1)/2;j++)
		if(a[j]<a[min]) min=j;
	if(min!=i){
		temp=a[i];
	    a[i]=a[min];
	    a[min]=temp; }
	for(j=n-i;j>(n+1)/2;j--)
	if(a[j]>a[max])max=j;
	if(max!=n-i+1){
	temp=a[n-i+1];
	a[n-i+1]=a[max];
	a[max]=temp;
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
