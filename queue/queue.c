#include<stdio.h>


int main(){
int n;
printf("enter the maximum no of elements");
scanf("%d",&n);
int q[n];
for (int i=0;i<n;i++){
 printf("enter the %d of the queue",i);
 scanf("%d",&q[i]);}

 printf("showing the queues elements");
 for(int i=0;i<n;i++)
{
   printf("%d",q[i]) ;
}


}

 