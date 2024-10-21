#include <stdio.h>
#include <stdlib.h>


int main() 
{
 int *score;
 int h;
 int k;
 int i,j;
 int tmp;
 
 
 scanf("%d", &h);
 scanf("%d", &k);
 score=(int*)malloc(sizeof(int)*h);
 
 
 for (i=0;i<h;i++){
  scanf("%d",&score[i]); 
 }
 if (h%2==0){
  printf("%d\n",score[h/2-1]);
  if (score[h/2-1]>=k){
   printf("BETTER LUCK NEXT TIME!\n");
  }
  else{
   printf("WINNER WINNER CHICKEN DINNER!\n");
  }
 }
 else{
  printf("%d\n",score[(h-1)/2]);
  if (score[(h-1)/2]>=k){
   printf("BETTER LUCK NEXT TIME!\n");
  }
  else{
   printf("WINNER WINNER CHICKEN DINNER!\n");
  }
 }
 
 free(score);
 return 0;
}