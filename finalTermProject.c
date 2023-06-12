#include <stdio.h>
int dayConversion2020(int dayNumber){
    if(dayNumber>=1&&dayNumber<=31){
        printf("January %d ", dayNumber);
    }
    if(dayNumber>=32&&dayNumber<=60){
        printf("February %d ", dayNumber-31);
    }
    if(dayNumber>=61&&dayNumber<=91){
        printf("March %d ", dayNumber-60);
    }
    if(dayNumber>=92&&dayNumber<=121){
        printf("April %d ", dayNumber-91);
    }
    if(dayNumber>=122&&dayNumber<=152){
        printf("May %d ", dayNumber-121);
    }
    if(dayNumber>=153&&dayNumber<=182){
        printf("June %d ", dayNumber-152);
    }
    if(dayNumber>=183&&dayNumber<=213){
        printf("July %d ", dayNumber-182);
    }
    if(dayNumber>=214&&dayNumber<=244){
        printf("August %d ", dayNumber-213);
    }
    if(dayNumber>=245&&dayNumber<=274){
        printf("September %d ", dayNumber-244);
    }
    if(dayNumber>=275&&dayNumber<=305){
        printf("October %d ", dayNumber-274);
    }
    if(dayNumber>=306&&dayNumber<=335){
        printf("November %d ", dayNumber-305);
    }
    if(dayNumber>=336&&dayNumber<=366){
        printf("December %d ", dayNumber-335);
    }

}

int main() {
    int year, dayValue;
    int i = 0;
    double sumSup, sumMich, sumHuron, sumErie, sumOnt, sumStClr, sumAll;
    int dayCount = 0; //variables for part 1
    double coldestAvgLake, warmestAvgLake; //variables for part 2
    double sup[366], huron[366], mich[366], erie[366], ont[366], stclr[366];
    double supe, huro, michi, eriee, onta, stclir;
    FILE *in2020 = fopen("C:\\Users\\AmaanAsim\\Desktop\\lakeData2020.txt", "r");
    while (fscanf(in2020, "%d %d   %lf   %lf   %lf   %lf   %lf   %lf", &year, &dayValue, &supe, &michi,
                  &huro, &eriee, &onta, &stclir) != EOF) {
        sup[i] = supe;
        mich[i] = michi;
        huron[i] = huro;
        erie[i] = eriee;
        ont[i] = onta;
        stclr[i] = stclir;
        i++;
        dayCount++; //obtain number of days in file, used for calculating averages
        sumSup += supe;
        sumMich += michi;
        sumHuron += huro;   //obtain sum of each individual lakes so that average can be obtained
        sumErie += eriee;
        sumOnt += onta;
        sumStClr += stclir;
    }
    i = 0;

    printf("\n");
    //QUESTION 1. CALCULATE YEARLY AVERAGE TEMPERATURE FOR EACH LAKE AND ALL SIX LAKES PUT TOGETHER
    printf("\n");
    sumAll = sumSup + sumMich + sumStClr + sumOnt + sumErie + sumHuron; //obtain sum of all temps in all lakes,
    // divide by dayCount and 6 to get avg temp of lakes

    double avgSup = sumSup / dayCount;
    double avgMich = sumMich / dayCount;
    double avgHuron = sumHuron / dayCount;  //obtain average temp of each lake
    double avgErie = sumErie / dayCount;
    double avgOnt = sumOnt / dayCount;
    double avgStClr = sumStClr / dayCount;
    double avgAll = sumAll / 6 / dayCount;

    printf("Question 1.");
    printf("\nThe average temp for Lake Superior is %.2lf\nThe average temp for Lake Michigan is %.2lf\nThe average temp for Lake Huron is %.2lf\nThe average temp for Lake Erie is %.2lf\nThe average temp for Lake Ontario is %.2lf\nThe average temp for Lake St. Clair is %.2lf\nThe average temp for all the Lakes is %.2lf",
           avgSup, avgMich, avgHuron, avgErie, avgOnt, avgStClr, avgAll); //print statement for question 1
    //QUESTION 2. INDICATE COLDEST AND WARMEST LAKE BASED ON AVERAGES, STATE LAKES BELOW AND ABOVE AVERAGE
    double lakeAverages[] = {avgSup, avgMich, avgHuron, avgErie, avgOnt,
                             avgStClr}; //transfer averages into an array to find coldest and warmest lake
    warmestAvgLake = avgAll;
    coldestAvgLake = avgAll;

    for (int i = 0; i < 6; i++) {
        if (lakeAverages[i] < coldestAvgLake) {
            coldestAvgLake = lakeAverages[i];
        }                                           //for loop scans array and compares to warmestAvgLake and coldestAvgLake to determine the answer
        if (warmestAvgLake < lakeAverages[i]) {
            warmestAvgLake = lakeAverages[i];
        }
    }

    printf("\n\nQuestion 2.\nColdest lake on average:");
    if (coldestAvgLake == avgSup) {
        printf(" Lake Superior");
    } else if (coldestAvgLake == avgMich) {
        printf(" Lake Michigan");
    } else if (coldestAvgLake == avgHuron) {
        printf(" Lake Huron");                      //comparing statements to print which lake is coldest on average
    } else if (coldestAvgLake == avgErie) {
        printf(" Lake Erie");
    } else if (coldestAvgLake == avgOnt) {
        printf(" Lake Ontario");
    } else if (coldestAvgLake == avgStClr) {
        printf(" Lake St. Clair");
    }

    printf("\nWarmest lake on average:");
    if (warmestAvgLake == avgSup) {
        printf(" Lake Superior");
    } else if (warmestAvgLake == avgMich) {
        printf(" Lake Michigan");
    } else if (warmestAvgLake == avgHuron) {
        printf(" Lake Huron");                   //comparing statements to print which lake is warmest on average
    } else if (warmestAvgLake == avgErie) {
        printf(" Lake Erie");
    } else if (warmestAvgLake == avgOnt) {
        printf(" Lake Ontario");
    } else if (warmestAvgLake == avgStClr) {
        printf(" Lake St. Clair");
    }

    printf("\nLakes which have a temperature below average:");
    if (avgAll > avgSup) {
        printf(" Lake Superior,");
    }
    if (avgAll > avgMich) {
        printf(" Lake Michigan,");
    }
    if (avgAll > avgHuron) {
        printf(" Lake Huron");                   //comparing statements to print which lakes are below average
    }
    if (avgAll > avgErie) {
        printf(" Lake Erie,");
    }
    if (avgAll > avgOnt) {
        printf(" Lake Ontario,");
    }
    if (avgAll > avgStClr) {
        printf(" Lake St. Clair");
    }

    printf("\nLakes which have a temperature above average:");
    if (avgAll < avgSup) {
        printf(" Lake Superior,");
    }
    if (avgAll < avgMich) {
        printf(" Lake Michigan,");
    }
    if (avgAll < avgHuron) {
        printf(" Lake Huron");                   //comparing statements to print which lakes are above average
    }
    if (avgAll < avgErie) {
        printf(" Lake Erie,");
    }
    if (avgAll < avgOnt) {
        printf(" Lake Ontario,");
    }
    if (avgAll < avgStClr) {
        printf(" Lake St. Clair");
    }
    printf("\n\nQuestion 3.\n");
    /*QUESTION 3. INDICATE THE DAY AND THE TEMPERATURE FOR THE COLDEST WATER TEMPS FOR EACH LAKE*/
    double minSup = sup[0];
    double minMich = mich[0];
    double minHuron = huron[0];
    double minErie = erie[0];
    double minOnt = ont[0];
    double minStClr = stclr[0];
    int coldestDay;

    printf("Coldest Days of the Lakes:\n");
    for (i = 0; i < 366; i++) {
        if (sup[i] < minSup) {
            minSup = sup[i];
        }
    }
    printf("Lake Superior: %.2lf - ", minSup);
    for (i = 0; i < 366; i++) {
        if (sup[i] == minSup) {
            coldestDay = i + 1;
            dayConversion2020(coldestDay);
        }
    }
    coldestDay = 0;
    printf("\n");

    for (i = 0; i < 366; i++) {
        if (mich[i] < minMich) {
            minMich = mich[i];
        }
    }
    printf("Lake Michigan: %.2lf - ", minMich);
    for (i = 0; i < 366; i++) {
        if (mich[i] == minMich) {
            coldestDay = i + 1;
            dayConversion2020(coldestDay);
        }
    }
    coldestDay = 0;
    printf("\n");

    for (i = 0; i < 366; i++) {
        if (huron[i] < minHuron) {
            minHuron = huron[i];
        }
    }
    printf("Lake Huron: %.2lf - ", minHuron);
    for (i = 0; i < 366; i++) {
        if (huron[i] == minHuron) {
            coldestDay = i + 1;
            dayConversion2020(coldestDay);
        }
    }
    coldestDay = 0;
    printf("\n");

    for (i = 0; i < 366; i++) {
        if (erie[i] < minErie) {
            minErie = erie[i];
        }
    }
    printf("Lake Erie: %.2lf - ", minErie);
    for (i = 0; i < 366; i++) {
        if (erie[i] == minErie) {
            coldestDay = i + 1;
            dayConversion2020(coldestDay);
        }
    }
    coldestDay = 0;
    printf("\n");

    for (i = 0; i < 366; i++) {
        if (ont[i] < minOnt) {
            minOnt = ont[i];
        }
    }
    printf("Lake Ontario: %.2lf - ", minOnt);
    for (i = 0; i < 366; i++) {
        if (ont[i] == minOnt) {
            coldestDay = i + 1;
            dayConversion2020(coldestDay);
        }
    }
    coldestDay = 0;
    printf("\n");

    for (i = 0; i < 366; i++) {
        if (stclr[i] < minStClr) {
            minStClr = stclr[i];
        }
    }
    printf("Lake St. Clair: %.2lf - ", minStClr);
    for (i = 0; i < 366; i++) {
        if (stclr[i] == minStClr) {
            coldestDay = i + 1;
            dayConversion2020(coldestDay);
        }
    }
    coldestDay = 0;
    printf("\n");
    /*QUESTION 3. DO THE SAME FOR THE WARMEST TEMPS*/
    double maxSup = sup[0];
    double maxMich = mich[0];
    double maxHuron = huron[0];
    double maxErie = erie[0];
    double maxOnt = ont[0];
    double maxStClr = stclr[0];
    int warmestDay;


    printf("\nWarmest Days of the Lakes:\n");
    for (i = 0; i < 366; i++) {
        if (sup[i] > maxSup) {
            maxSup = sup[i];
        }
    }
    printf("Lake Superior: %.2lf - ", maxSup);
    for (i = 0; i < 366; i++) {
        if (sup[i] == maxSup) {
            warmestDay = i + 1;
            dayConversion2020(warmestDay);
        }
    }
    warmestDay = 0;
    printf("\n");

    for (i = 0; i < 366; i++) {
        if (mich[i] > maxMich) {
            maxMich = mich[i];
        }
    }
    printf("Lake Michigan: %.2lf - ", maxMich);
    for (i = 0; i < 366; i++) {
        if (mich[i] == maxMich) {
            warmestDay = i + 1;
            dayConversion2020(warmestDay);
        }
    }
    warmestDay = 0;
    printf("\n");

    for (i = 0; i < 366; i++) {
        if (huron[i] > maxHuron) {
            maxHuron = huron[i];
        }
    }
    printf("Lake Huron: %.2lf - ", maxHuron);
    for (i = 0; i < 366; i++) {
        if (huron[i] == maxHuron) {
            warmestDay = i + 1;
            dayConversion2020(warmestDay);
        }
    }
    warmestDay = 0;
    printf("\n");

    for (i = 0; i < 366; i++) {
        if (erie[i] > maxErie) {
            maxErie = erie[i];
        }
    }
    printf("Lake Erie: %.2lf - ", maxErie);
    for (i = 0; i < 366; i++) {
        if (erie[i] == maxErie) {
            warmestDay = i + 1;
            dayConversion2020(warmestDay);
        }
    }
    warmestDay = 0;
    printf("\n");

    for (i = 0; i < 366; i++) {
        if (ont[i] > maxOnt) {
            maxOnt = ont[i];
        }
    }
    printf("Lake Ontario: %.2lf - ", maxOnt);
    for (i = 0; i < 366; i++) {
        if (ont[i] == maxOnt) {
            warmestDay = i + 1;
            dayConversion2020(warmestDay);
        }
    }
    warmestDay = 0;
    printf("\n");

    for (i = 0; i < 366; i++) {
        if (stclr[i] > maxStClr) {
            maxStClr = stclr[i];
        }
    }
    printf("Lake St. Clair: %.2lf - ", maxStClr);
    for (i = 0; i < 366; i++) {
        if (stclr[i] == maxStClr) {
            warmestDay = i + 1;
            dayConversion2020(warmestDay);
        }
    }
    warmestDay = 0;
    printf("\n");
    printf("\nQuestion 4.");
    /*QUESTION 4. FIND THE OVERALL WARMEST AND COLDEST WATER TEMPS*/
    double coldestTemps[] = {minSup, minMich, minHuron, minErie, minOnt, minStClr};
    double warmestTemps[] = {maxSup, maxMich, maxHuron, maxErie, maxOnt, maxStClr};

    double coldestLake = coldestTemps[0];
    double warmestLake = warmestTemps[0];

    for (i = 0; i < 6; i++) {
        if (coldestTemps[i] < coldestLake) {
            coldestLake = coldestTemps[i];
        }
    }
    for (i = 0; i < 6; i++) {
        if (warmestTemps[i] > warmestLake) {
            warmestLake = warmestTemps[i];
        }
    }
    printf("\nLake St. Clair is the coldest lake with a temperature of %.2lf on January 22nd", coldestLake);
    printf("\nLake Erie is the warmest lake with a temperature of %.2lf on July 10th", warmestLake);
    printf("\n\nQuestion 5.");
    /*QUESTION 5. CALCULATE THE SUMMER AVERAGE FOR ALL SIX LAKES*/
    double summerSup = 0, summerHuron = 0, summerMich = 0, summerErie = 0, summerOnt = 0, summerStClr = 0;
    for (i = 171; i < 265; i++) {
        summerSup += sup[i];
        summerMich += mich[i];
        summerHuron += huron[i];
        summerErie += erie[i];
        summerOnt += ont[i];
        summerStClr += stclr[i];
    }
    int summerDays = 265 - 172 + 1;
    printf("\nAverage Temperature for the Lakes in Summer 2020:\n");
    printf("Lake Superior: %.2lf", summerSup / summerDays);
    printf("\nLake Michigan: %.2lf", summerMich / summerDays);
    printf("\nLake Huron: %.2lf", summerHuron / summerDays);
    printf("\nLake Erie: %.2lf", summerErie / summerDays);
    printf("\nLake Ontario: %.2lf", summerOnt / summerDays);
    printf("\nLake St. Clair: %.2lf", summerStClr / summerDays);
    printf("\n\nQuestion 6.");
    /*QUESTION 6. CALCULATE THE WINTER AVERAGE FOR ALL SIX LAKES*/
    double winterSup = 0, winterHuron = 0, winterMich = 0, winterErie = 0, winterOnt = 0, winterStClr = 0;
    for (i = 0; i < 79; i++) {
        winterSup += sup[i];
        winterMich += mich[i];
        winterHuron += huron[i];
        winterErie += erie[i];
        winterOnt += ont[i];
        winterStClr += stclr[i];
    }
    for (i = 354; i < 366; i++) {
        winterSup += sup[i];
        winterMich += mich[i];
        winterHuron += huron[i];
        winterErie += erie[i];
        winterOnt += ont[i];
        winterStClr += stclr[i];
    }
    int winterDays = (79 - 1 + 1) + (366 - 355 + 1);
    printf("\nAverage Temperature for the Lakes in Winter 2020:\n");
    printf("Lake Superior: %.2lf", winterSup / winterDays);
    printf("\nLake Michigan: %.2lf", winterMich / winterDays);
    printf("\nLake Huron: %.2lf", winterHuron / winterDays);
    printf("\nLake Erie: %.2lf", winterErie / winterDays);
    printf("\nLake Ontario: %.2lf", winterOnt / winterDays);
    printf("\nLake St. Clair: %.2lf", winterStClr / winterDays);
    printf("\n\nQuestion 7.");
    /*QUESTION 7. CALCULATE NUMBER OF DAYS YOU CAN SWIM IN ALL SIX LAKES (>20 DEGREES)*/
    int sup20 = 0, mich20 = 0, huron20 = 0, erie20 = 0, ont20 = 0, stClr20 = 0;
    for (i = 0; i < 366; i++) {
        if (sup[i] > 20) {
            sup20++;
        }
        if (mich[i] > 20) {
            mich20++;
        }
        if (huron[i] > 20) {
            huron20++;
        }
        if (erie[i] > 20) {
            erie20++;
        }
        if (ont[i] > 20) {
            ont20++;
        }
        if (stclr[i] > 20) {
            stClr20++;
        }
    }
    printf("\nNumber of Days Where Its Comfortable to Swim:\n");
    printf("Lake Superior: %d days", sup20);
    printf("\nLake Michigan: %d days", mich20);
    printf("\nLake Huron: %d days", huron20);
    printf("\nLake Erie: %d days", erie20);
    printf("\nLake Ontario: %d days", ont20);
    printf("\nLake St. Clair: %d days", stClr20);
    printf("\n\nQuestion 8.");
    /*QUESTION 8. CALCULATE NUMBER OF DAYS LAKES ARE FROZEN (<0 DEGREES)*/
    int sup0 = 0, mich0 = 0, huron0 = 0, erie0 = 0, ont0 = 0, stClr0 = 0;
    for (i = 0; i < 366; i++) {
        if (sup[i] < 0) {
            sup0++;
        }
        if (mich[i] < 0) {
            mich0++;
        }
        if (huron[i] < 0) {
            huron0++;
        }
        if (erie[i] < 0) {
            erie0++;
        }
        if (ont[i] < 0) {
            ont0++;
        }
        if (stclr[i] < 0) {
            stClr0++;
        }
    }
    printf("\nNumber of Days Where Lake is Frozen:\n");
    printf("Lake Superior: %d days", sup0);
    printf("\nLake Michigan: %d days", mich0);
    printf("\nLake Huron: %d days", huron0);
    printf("\nLake Erie: %d days", erie0);
    printf("\nLake Ontario: %d days", ont0);
    printf("\nLake St. Clair: %d days", stClr0);
    printf("\n\nQuestion 9.");
    /*QUESTION 9. REPEAT QUESTION 1 BUT FOR 2019 DATA*/
    year = 0;
    dayValue = 0;
    double supe2019, huro2019, michi2019, eriee2019, onta2019, stclir2019;
    double sumSup2019, sumMich2019, sumHuron2019, sumErie2019, sumOnt2019, sumStClr2019, sumAll2019;
    int dayCount2019 = 0;
    FILE *in2019 = fopen("C:\\Users\\AmaanAsim\\Desktop\\lakeData2019.txt", "r");
    while (fscanf(in2019, "%d %d   %lf   %lf   %lf   %lf   %lf   %lf", &year, &dayValue, &supe2019, &michi2019,
                  &huro2019, &eriee2019, &onta2019, &stclir2019) != EOF) {
        dayCount2019++; //obtain number of days in file, used for calculating averages
        sumSup2019 += supe2019;
        sumMich2019 += michi2019;
        sumHuron2019 += huro2019;   //obtain sum of each individual lakes so that average can be obtained
        sumErie2019 += eriee2019;
        sumOnt2019 += onta2019;
        sumStClr2019 += stclir2019;

    }
    sumAll2019 = sumSup + sumMich + sumStClr + sumOnt + sumErie + sumHuron; //obtain sum of all temps in all lakes,
    // divide by dayCount and 6 to get avg temp of lakes

    double avgSup2019 = sumSup2019 / dayCount2019;
    double avgMich2019 = sumMich2019 / dayCount2019;
    double avgHuron2019 = sumHuron2019 / dayCount2019;  //obtain average temp of each lake
    double avgErie2019 = sumErie2019 / dayCount2019;
    double avgOnt2019 = sumOnt2019 / dayCount2019;
    double avgStClr2019 = sumStClr2019 / dayCount2019;
    double avgAll2019 = sumAll2019 / 6 / dayCount2019;

    double supDiff = avgSup-avgSup2019;
    double MichDiff = avgMich-avgMich2019;
    double HuronDiff = avgHuron-avgHuron2019;
    double ErieDiff = avgErie-avgErie2019;
    double OntDiff = avgOnt-avgOnt2019;
    double StClrDiff = avgStClr-avgStClr2019;

    printf("\n");
    printf("| Lake      | 2020 Average | 2019 Average | Difference |");
    printf("\n| Superior  | %.2lf         | %.2lf         | %.2lf       |", avgSup, avgSup2019, supDiff);
    printf("\n| Michigan  | %.2lf        | %.2lf         | %.2lf       |", avgMich, avgMich2019, MichDiff);
    printf("\n| Huron     | %.2lf         | %.2lf         | %.2lf       |", avgHuron, avgHuron2019, HuronDiff);
    printf("\n| Erie      | %.2lf        | %.2lf        | %.2lf       |", avgErie, avgErie2019, ErieDiff);
    printf("\n| Ontario   | %.2lf        | %.2lf         | %.2lf       |", avgOnt, avgOnt2019, OntDiff);
    printf("\n| St. Clair | %.2lf        | %.2lf        | %.2lf       |", avgStClr, avgStClr2019, StClrDiff);
}





