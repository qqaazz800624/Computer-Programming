#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){

    char input[128];
    double decimal_sum = 0.0;

    while (1){
        if (fgets(input, sizeof(input), stdin) == NULL){
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "q") == 0){
            break;
        }

        char *endptr;
        double value = strtod(input, &endptr); 

        if (endptr != input && *endptr == '\0'){
            double integer_part;
            double decimal_part = modf(value, &integer_part);

            if (decimal_part < 0){
                decimal_part = -decimal_part;
            }

            decimal_sum += decimal_part;
        } else {
            continue;
        }
    }
    printf("%.2f\n", decimal_sum);

    return 0;
}