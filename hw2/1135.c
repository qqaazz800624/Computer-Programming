#include <stdio.h>
#include <stdlib.h>


int main() 
{
 int N;
 int *array;
 int i;
 int ans;
 
 scanf("%d",&N);
 
 array=(int*)malloc(sizeof(int)*N);
 for(i=0;i<N;i++){
  scanf("%d",array+i);
 }
 if (N%2==0){
  ans=(array[N/2-1]+array[N/2]+1)/2;
 }
 else{
  ans=array[N/2];
 }
 printf("%d",ans);
 puts("");
 free(array);
 return 0;
}