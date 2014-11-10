/*
# @EXPECTED_RESULTS@: CORRECT
*/

import java.time.DayOfWeek;
import java.time.LocalDate;
import java.time.Month;
import java.util.Scanner;

public class Main{

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int startDay = in.nextInt();
        int startMonth = in.nextInt();
        int startYear = in.nextInt();
        in.next();
        int endDay = in.nextInt();
        int endMonth = in.nextInt();
        int endYear = in.nextInt();

        LocalDate startDate = LocalDate.of(startYear, startMonth, startDay);
        LocalDate endDate = LocalDate.of(endYear, endMonth, endDay);

        /* Check if we need to check the first year */
        if(isAfterFebruary(startDate)){
            startDate = startDate.plusYears(1);
        }

        /* Set the day to the last day in february */
        startDate = LocalDate.of(startDate.getYear(), Month.MARCH, 1);
        startDate = startDate.minusDays(1);

        int counter = 0;
        while( ! startDate.isAfter(endDate)){
            if(startDate.isLeapYear() && isWeekend(startDate)){
                counter++;
            }

            /* Set the day to the last day in february */
            startDate = LocalDate.of(startDate.getYear() + 1, Month.MARCH, 1);
            startDate = startDate.minusDays(1);
        }

        System.out.print(counter);
    }


    private static boolean isWeekend(LocalDate date){
        return date.getDayOfWeek() == DayOfWeek.FRIDAY || date.getDayOfWeek() == DayOfWeek.SATURDAY;
    }

    private static boolean isAfterFebruary(LocalDate date){
        LocalDate firstOfMarch = LocalDate.of(date.getYear(), Month.MARCH, 1);
        if(date.isBefore(firstOfMarch)){
            return false;
        }else {
            return true;
        }
    }
}
