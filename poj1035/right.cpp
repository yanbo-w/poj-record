#include <iostream>
#include <string.h>

using namespace std;

#define MAX 10010
#define MAXL 20

char D[MAX][MAXL];
int Dp;
char C[MAXL];







bool replace(char *A,char *B)
{
 int l1=strlen(A);
 int l2=strlen(B);
 int i=0;
 if(l1==l2)
 {
  while(i<l1&&A[i]==B[i])
	  i++;
  while(++i<l1)
	  if(A[i]!=B[i])
	  return false;
 }else if(l1==l2+1)
 {
   while(i<l2&&A[i]==B[i])
	  i++;
  
   while(++i<l1)
    if(A[i]!=B[i-1])
		return false;
 }else if(l1+1==l2)
 {
   while(i<l1&&A[i]==B[i])
	   i++;
  
   while(++i<l2)
	   if(A[i-1]!=B[i])
		   return false;
 }else
	 return false;

return true;
}

int main()
{
	freopen("data.in","r",stdin);

 Dp=0;
 while(scanf("%s",D[Dp++])&&strcmp(D[Dp-1],"#")!=0)
	 ;
 Dp--;
 while(scanf("%s",C)&&strcmp(C,"#")!=0)
 {
	 bool Found=false;
  for(int i=0;i!=Dp;i++)
   if(strcmp(D[i],C)==0)
   {
    Found=true;
	break;
   }

 if(Found)
	 printf("%s is correct\n",C);
 else
 {
	 printf("%s:",C);
 for(int i=0;i!=Dp;i++)
	 if(replace(D[i],C))
		 printf(" %s",D[i]);
	 printf("\n");
 }


 }
return 0;
}