#include<stdio.h>
#include <stdlib.h>
void main()
{
  int n,i,j,k,sum=0,seek=0,diff;
  int d[20];
  float avg;
  printf("Enter the no of requests:\n");
  scanf("%d",&n);
  printf("Enter the requests:\n");
  for(i=1;i<=n;i++)
  {
    scanf("%d",&d[i]);
  }
  printf("Enter the initial head position:\n");
  scanf("%d",&k);
  d[0]=k;
  printf("\n");
  for(j=0;j<=n-1;j++)
  {
    diff=abs(d[j+1]-d[j]);
    seek+=diff;
    printf("Move from %d to %d with Seek %d\n",d[j],d[j+1],diff);
  }
  printf("\nTotal Seek Time is %d\t",seek);
  avg=seek/(float)n;
  printf("\nAverage Seek Time is %f\t",avg);
  return 0;
}
