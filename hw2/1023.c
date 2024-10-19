#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main() 
{
   int num;
   int *height;
   int i;
   int highest=-10000;
   int highest_place;
   int lowest=10000;
   int lowest_place;
   
   scanf("%d",&num);
   height=(int*)malloc(sizeof(int)*num);
   
   for (i=0;i<num;i++){
     scanf("%d",&*(height+i));
     if (height[i]>highest){
      highest=height[i];
      highest_place=i+1;
    }
     if (height[i]<lowest){
      lowest=height[i];
      lowest_place=i+1;
    }
   }

   printf("%d %d\n", highest_place, highest);
   printf("%d %d\n", lowest_place, lowest);
   free(height);
   return 0;
}