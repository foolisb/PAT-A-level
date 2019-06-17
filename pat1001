#include<stdio.h>
#include<stdlib.h>
int main()
{
  int a,b,sum;
  int m,t,h,q;
  scanf("%d %d",&a,&b);
  sum = a+b;
  q = abs(sum);
  h = q%1000;
  t = (q/1000)%1000;
  m = (q/1000)/1000;
  if(sum > 0)
          {
              if(m != 0)
                 printf("%d,%03d,%03d",m,t,h);
              else if(t != 0)
                 printf("%d,%03d",t,h);
              else
                 printf("%d",h);
          }
  else if(sum < 0)
          {
              if(m != 0)
                 printf("-%d,%03d,%03d",m,t,h);
              else if(t != 0)
                 printf("-%d,%03d",t,h);
              else
                 printf("-%d",h);
          }
  else 
          printf("%d",0);
 
  return 0;
}

