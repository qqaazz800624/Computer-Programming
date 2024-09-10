#include <stdio.h>

int main()
{
    int score, grade;
    printf("(1) 大學部 (2) 研究所：");
    scanf("%d", &grade);
    if (grade != 1 && grade != 2){  // input check
        printf("Invalid grade\n");
        return 0;
    }

    printf("請輸入您的分數：");
    scanf("%d", &score);
    if (score < 0 || score > 100){  // input check
        printf("Invalid score\n");
        return 0;
    }

    if (score < 60 && grade ==1){  // grade == 1 is actually not necessary
        printf("fail\n");
    }
    else if (score < 70 && grade ==2){
        printf("fail\n");
    }
    else{
        printf("pass\n");
    }

    return 0;
}