/*
# @EXPECTED_RESULTS@: CORRECT
*/
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int is_weekend(int day, int month, int year) {
    struct tm *timeinfo;
    time_t rawtime;

     /* get current timeinfo and modify it to given date*/
    time( &rawtime );
    timeinfo = localtime( &rawtime );
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;

    mktime(timeinfo);

    int weekday = timeinfo->tm_wday;
    if(weekday == 5 || weekday == 6){
        return 1;
    }
    return 0;
}


int isLeapYear(int year){

    /* If not divisible of 4 */
    if(year % 4 != 0){
        return 0;
    }

    /* If divisible by 4, but not 100 */
    if(year % 100 != 0){
        return 1;
    }

    if(year % 400 != 0){
        return 0;
    }

    return 1;
}

int main(int argc, char* argv[])
{
    int startDay, startMonth, startYear, endDay, endMonth, endYear;
    scanf("%d %d %d - %d %d %d", &startDay, &startMonth, &startYear, &endDay, &endMonth, &endYear);

    /* Check the first year */
    if(startMonth > 2){
        startYear++;
    }

    int counter = 0;
    while(startYear < endYear){
        if(isLeapYear(startYear)){
            if(is_weekend(29, 2, startYear)){
                counter++;
            }
        }
        startYear++;
    }

    /* Check the  last year */
    if(isLeapYear(endYear)){
        /* Check if end date is last of february */
        if(endMonth == 2 && endDay == 29){
            counter+= is_weekend(29, 02, endYear);
        }else if(endMonth > 2){
            counter+= is_weekend(29, 02, endYear);
        }
    }

    printf("%d", counter);
    return 0;
}
