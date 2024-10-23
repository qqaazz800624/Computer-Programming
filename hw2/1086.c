#include <stdio.h>
#include <stdlib.h>


int main() 
{
 int N;
 char C1;
 double F;
 char S1[255];
 char C2;
 char S2[127];
 //double first;
 int i;
 
 scanf("%d",&N);
 scanf(" %c",&C1);
 scanf("%lf",&F);
 getchar();
 fgets(S1, sizeof(S1), stdin);
 scanf(" %c",&C2);
 scanf("%s",S2);
 
 printf("%.2lf\n", N+F);
 
 int second=N+(int)C1;
 printf("%c %d\n",(char)second,second);
 
 int third=(int)F+(int)C2;
 printf("%c %d\n",(char)third,third);
 
 for (i=0;i<255;i++){
  if(S1[i]>='A' && S1[i]<='Z'){
   S1[i]+=32;
  }
  if(S1[i]=='\0'){
   break;
  }
 }
 printf("%s", S1);
 
 for (i=0;i<127;i++){
  if(S2[i]>='a' && S2[i]<='z'){
   S2[i]-=32;
  }
  if(S2[i]=='\0'){
   break;
  }
 }
 printf("%s\n", S2);
 
 return 0;
}