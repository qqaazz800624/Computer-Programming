#include <stdio.h>

// BMI Calculator

int main(){
    double weight, height, bmi;
    const char *result;
    
    scanf("%lf", &height);
    scanf("%lf", &weight);

    height = height / 100;
    bmi = weight / (height * height);

    if (bmi < 18.5){
        result = "Underweight";
    }
    else if (bmi >= 18.5 && bmi < 24){
        result = "Normal";
    }
    else if (bmi >= 24 && bmi < 27){
        result = "Overweight";
    }
    else if (bmi >= 27 && bmi < 30){
        result = "Obese Class I";
    }
    else if (bmi >= 30 && bmi < 35){
        result = "Obese Class II";
    }
    else {
        result = "Obese Class III";
    }
    printf("%.2f\n", bmi);
    printf("%s\n", result);

    return 0;
}