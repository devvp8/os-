#include <stdio.h>
#include <stdlib.h>
void printtm(int t[], int n)
{
int tm = 0;
printf("\n");
for (int i = 0; i < n; i++)
{
if (i != 0)
{
printf("->%d", t[i]);
tm = tm + abs(t[i] - t[i - 1]);
}
else
{
printf("%d", t[i]);
}
}
printf("\nTotal number of track movements : %d", tm);
printf("\nAverage seek time : %d\n\n", tm/n);
}


void scan(int q[], int tn, int h, int n)
{
int tm[200], j = 0, tb[200], b = 0;
tm[j++] = h;
for (int i = 0; i < n; i++)
{
if (q[i] >= h)
{
tm[j++] = q[i];
}
else
{
tb[b++] = q[i];
}
}
tm[j++] = tn - 1;

for (int i = b - 1; i >= 0; i--)
{
tm[j++] = tb[i];
}
printtm(tm, j);
}

int main()
{
int queue[] = {82,170,43,140,24,16,190};
int qsize = sizeof(queue) / sizeof(queue[0]);
int vis[100];
for (int i=0;i<qsize;i++){vis[i]=0;}
// printf("%d",vis[qsize+1]);
int trackno = 200;
int head = 50, t;
printf("Request : ");
for(int i =0;i<qsize;i++){printf("%d, ",queue[i]);}
printf("\nHead : %d\nTotal Tracks : %d \nScheduling algorithms ->\n",head,trackno);
for (int i = 0; i < qsize - 1; i++)
{
for (int j = 0; j < qsize - 1; j++)
{
if (queue[j] > queue[j + 1])
{
t = queue[j];
queue[j] = queue[j + 1];
queue[j + 1] = t;
}
}
}
printf("SCAN : ");
scan(queue, trackno, head, qsize);
return 0;
}
