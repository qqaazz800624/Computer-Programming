#include "safe.h"


int safe(int ary[5][5])
{
 int i, j;
 int y,x;
 int list[4];
 int step_up=0;
 int step_right=0;
 int step_down=0;
 int step_left=0;
 int step_ans=1000;
 int step_ans_pos;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(ary[i][j]==2){
             y=i;
             x=j;
   }
        }
    }
    //往上 
    for(i=y;i>=0;i--){
     if (ary[i][x]==1){
      step_up=y-i;
      list[0]=step_up;
      break;
  }
  step_up=1000;
  list[0]=step_up;
 }
  //往右 
    for(i=x;i<5;i++){
     if (ary[y][i]==1){
      step_right=i-x;
      list[1]=step_right;
      break;
  }
  step_right=1000;
  list[1]=step_right;
 }
 //往下 
    for(i=y;i<5;i++){
     if (ary[i][x]==1){
      step_down=i-y;
      list[2]=step_down;
      break;
  }
  step_down=1000;
  list[2]=step_down;
 }
 //往左 
    for(i=x;i>=0;i--){
     if (ary[y][i]==1){
      step_left=x-i;
      list[3]=step_left;
      break;
  }
  step_left=1000;
  list[3]=step_left;
 }
 for(i=0;i<4;i++){
  if(list[i]<step_ans){
   step_ans=list[i];
   step_ans_pos=i+1;
  }
 }
 return step_ans_pos;
}