#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char date[11];
    char time[6];
    double longitude;
    double latitude;
    double magnitude;
    double depth;
    char location[100];
} Earthquake;


int convertDateToInt(const char* date) {
    int year, month, day;
    sscanf(date, "%d/%d/%d", &year, &month, &day);
    return year * 10000 + month * 100 + day;
}

int compareByMagnitude(const void *a, const void *b) {
    Earthquake *e1 = (Earthquake *)a;
    Earthquake *e2 = (Earthquake *)b;
    if (e1->magnitude < e2->magnitude) return 1;
    if (e1->magnitude > e2->magnitude) return -1;
    return 0;
}

int main() {
    int startYear, startMonth, startDay;
    int endYear, endMonth, endDay;
    
    scanf("%d %d %d", &startYear, &startMonth, &startDay);
    scanf("%d %d %d", &endYear, &endMonth, &endDay);
    
    char startDateStr[11], endDateStr[11];
    sprintf(startDateStr, "%d/%d/%d", startYear, startMonth, startDay);
    sprintf(endDateStr, "%d/%d/%d", endYear, endMonth, endDay);
    
    int startDate = convertDateToInt(startDateStr);
    int endDate = convertDateToInt(endDateStr);

    Earthquake earthquakes[1000];
    int count = 0;

    while (1) {
        Earthquake e;
        char input[200];
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
            }  
        
        sscanf(input, "%d %s %s %lf %lf %lf %lf %[^\n]",
               &e.id, e.date, e.time, &e.longitude, &e.latitude, &e.magnitude, &e.depth, e.location);

        int quakeDate = convertDateToInt(e.date);

        if (quakeDate >= startDate && quakeDate <= endDate) {
            earthquakes[count++] = e; 
        }
    }

    if (count == 0) {
        printf("No Data\n");
        return 0;
    }

    qsort(earthquakes, count, sizeof(Earthquake), compareByMagnitude);

    printf("編號\t日期\t時間\t經度\t緯度\t規模\t深度\t位置\n");
    for (int i = 0; i < count; i++) {
        printf("%03d\t%s\t%s\t%.2f\t%.2f\t%.1f\t%.1f\t%s\n",
               earthquakes[i].id, earthquakes[i].date, earthquakes[i].time,
               earthquakes[i].longitude, earthquakes[i].latitude,
               earthquakes[i].magnitude, earthquakes[i].depth, earthquakes[i].location);
    }

    return 0;
}
