#include <stdio.h>
#include <string.h>

int main(){

    char filename[128] = {0};
    scanf("%s", filename);
    FILE *input_file;
    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return 1;
    }

    int pistol_count = 0, smg_count = 0, shotgun_count = 0, ar_count = 0, sniper_count = 0;
    char gun_name[20];

    while (fscanf(input_file, "%s", gun_name) != EOF) {
        if (strncmp(gun_name, "PISTOL", 6) == 0) {
            pistol_count++;
        } else if (strncmp(gun_name, "SMG", 3) == 0) {
            smg_count++;
        } else if (strncmp(gun_name, "SHOTGUN", 7) == 0) {
            shotgun_count++;
        } else if (strncmp(gun_name, "AR", 2) == 0) {
            ar_count++;
        } else if (strncmp(gun_name, "SNIPER", 6) == 0) {
            sniper_count++;
        }
    }
    fclose(input_file);

    printf("%d %d %d %d %d\n", pistol_count, smg_count, shotgun_count, ar_count, sniper_count);

    return 0;
}