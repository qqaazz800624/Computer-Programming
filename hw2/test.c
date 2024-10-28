#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Earthquake {
    int id;
    char date[11];
    char time[6];
    double longitude;
    double latitude;
    double magnitude;
    double depth;
    char location[100];
};

typedef struct Earthquake Earthquake;

int convertDateToInt(const char* date);
int compareByMagnitude(const void *a, const void *b);

int main() {
    
    int startYear, startMonth, startDay;
    int endYear, endMonth, endDay;
    int startDate, endDate;
    int count = 0;
    int i;

    scanf("%d %d %d", &startYear, &startMonth, &startDay);
    scanf("%d %d %d", &endYear, &endMonth, &endDay);

    char startDateStr[11], endDateStr[11];
    sprintf(startDateStr, "%d/%d/%d", startYear, startMonth, startDay); // char 2024/03/01
    sprintf(endDateStr, "%d/%d/%d", endYear, endMonth, endDay);        // char 2024/03/31

    startDate = convertDateToInt(startDateStr);  // int 20240301 
    endDate = convertDateToInt(endDateStr);      // int 20240331 

    Earthquake *earthquakes;
    earthquakes = (Earthquake *)malloc(1000 * sizeof(Earthquake));
    
    while (1){
        Earthquake e;
        char input[200];
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        // if (strncmp(input, "-1", 2) == 0) {
        //     break;
        // }

        sscanf(input, "%d %s %s %lf %lf %lf %lf %[^\n]",
               &e.id, e.date, e.time, &e.longitude, &e.latitude, &e.magnitude, &e.depth, e.location);

        int quakeDate = convertDateToInt(e.date);

        if (quakeDate >= startDate && quakeDate <= endDate) {
            earthquakes[count] = e;
            count++;
        }
    }
    if (count == 0) {
        printf("No Data\n");
        free(earthquakes);
        return 0;
    }

    qsort(earthquakes, count, sizeof(Earthquake), compareByMagnitude);

    printf("編號\t日期\t時間\t經度\t緯度\t規模\t深度\t位置\n");
    for (i=0; i<count; i++){
        printf("%03d\t%s\t%s\t%.2f\t%.2f\t%.1f\t%.1f\t%s\n", 
                earthquakes[i].id, 
                earthquakes[i].date, 
                earthquakes[i].time, 
                earthquakes[i].longitude, 
                earthquakes[i].latitude, 
                earthquakes[i].magnitude, 
                earthquakes[i].depth, 
                earthquakes[i].location);
    }

    free(earthquakes);

    return 0;
}

int convertDateToInt(const char* date){
    int year, month, day;
    sscanf(date, "%d/%d/%d", &year, &month, &day);
    return year * 10000 + month * 100 + day;
}

int compareByMagnitude(const void *a, const void *b){
    Earthquake *e1 = (Earthquake *)a;
    Earthquake *e2 = (Earthquake *)b;
    if (e1->magnitude < e2->magnitude) {
        return 1;
    }
    if (e1->magnitude > e2->magnitude) {
        return -1;
    }
    return 0;
}