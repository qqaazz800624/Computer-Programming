#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int interval;
    char filename[128];

    scanf("%d", &interval);
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return 1;
    }

    char line[128];
    int line_number = 1;  

    while (fgets(line, sizeof(line), file)) {
        if (line_number % interval != 0) {
            line[strcspn(line, "\n")] = '\0';
            printf("%s ", line);
        }
        line_number++;
    }
    
    fclose(file);

    printf("\n");  
    return 0;
}
