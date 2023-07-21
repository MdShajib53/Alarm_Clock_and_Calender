#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

// Color Code-->Link = Link-->//https://www.theurbanpenguin.com/4184-2/
void Black(){
    printf("\033[0;30m");
}
void Red(){
    printf("\033[0;31m");
}
void Green(){
    printf("\033[0;32m");
}
void Yellow(){
    printf("\033[0;33m");
}
void Blue(){
    printf("\033[0;34m");
}
void Purple(){
    printf("\033[0;35m");
}
void Cyan(){
    printf("\033[0;36m");
}
void White(){
    printf("\033[0;37m");
}
void Reset(){
    printf("\033[0m");
}

// First Day
int getFirstDayOfTheYear(int year){
    int day=(year*365+((year-1)/4)-((year-1)/100)+((year-1)/400))%7;
    return day;
}
/*
   The algorithm used in the function, Zeller's Congruence,
   is generally accurate for dates after 1582, which is
   when the Gregorian calendar was adopted in most countries.
*/

// Leap Year
int february(int year){
    if(year%4==0 && year%100!=0){
        return 29;
    }
    else if(year%400==0){
        return 29;
    }
    return 28;
}

// Alarm Clock
void AlarmClock(){
    int hour,min,sec; //for system
    int h,m,s; //for user

    //Get the current time from system clock
    time_t now=time(NULL);
    struct tm* t=localtime(&now);
    hour=t->tm_hour;
    min=t->tm_min;
    sec=t->tm_sec;

    Cyan();
    printf("%70s\n","Enter Alarm Time(24 Hour Format)");
    Reset();
    Purple();
    printf("HOUR : ");
    scanf("%d",&h);
    printf("MINUTE : ");
    scanf("%d",&m);
    printf("SECOND : ");
    scanf("%d",&s);
    Reset();

    system("color A4");

    if(h>24 || m>60 || s>60){
        Red();
        printf("\t\tInvalid Time\n");
        printf("\t\tTry Again!!\n\n");
        Reset();
        system("color 04");
        printf("\n");
        return;
    }

    while(1){
        system("cls");
        printf("Alarm Time   = %d:%d:%d\n",h,m,s);
        printf("Current Time = %d:%d:%d\n",hour,min,sec+1);
        Sleep(1000);
        sec++;
        if(sec==60){
            sec=0;
            min++;
        }
        if(min==60){
            min=0;
            hour++;
        }
        if(hour==24){
            hour=0;
        }
        if(hour==h && min==m && sec==s){
            for(int beep=0;beep<5;beep++){
                Beep(750,800);
            }
            system("color 07");
            printf("\n");
            break;
        }
    }
}

// Calender
void calender(){
    int lastCheck=1;
    while(lastCheck){
        char *months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
        int totalDays,weekDay=0,spaceCounter=0;
        int specificMonth,specificDate,specificDay=-1;
        int daysInMonth[]={31,28,31,30,31,30,31,31,30,31,30,31};

        int year;
        Yellow();
        printf("Enter Your Required Year: ");
        scanf("%d",&year);
        Reset();

        Red();
        if(year<1583){
            printf("\nPlease Enter the Year above 1582 and try again\n");
            printf("Thank You\n\n");
            return;
        }
        Reset();

        Blue();
        printf("\nHere the Option:\n\n");
        Reset();
        Green();
        printf("0.Full Year\n");
        Reset();
        printf("1.January\n");
        printf("2.February\n");
        printf("3.March\n");
        printf("4.April\n");
        printf("5.May\n");
        printf("6.June\n");
        printf("7.July\n");
        printf("8.August\n");
        printf("9.September\n");
        printf("10.October\n");
        printf("11.Nobember\n");
        printf("12.December\n");
        printf("13.Specific Day\n");
        printf("14.Exit\n");

        Blue();
        int option;
        printf("\nEnter Option No: ");
        Red();
        scanf("%d",&option);
        Reset();
        if(option==13){
            printf("Enter Month(1-12) :");
            scanf("%d",&specificMonth);
            printf("Enter Date :");
            scanf("%d",&specificDate);
            if(specificMonth>12 || specificDate>31){
                Red();
                printf("\nPlease Enter current Month and Date\n");
                Reset();
            }
        }
        if(option>=14)break;

        if(option!=13){
            printf("\n");
            printf("\033[0;32m***********************************************\033[0m\n");
            printf("\033[0;32m*\033[0m               Welcome to %d               \033[0;32m*\033[0m\n",year);
            printf("\033[0;32m***********************************************\033[0m\n");
        }

        //February Month Check
        daysInMonth[1]=february(year);
        //First Day of the Year
        weekDay=getFirstDayOfTheYear(year);

        for(int i=0;i<12;i++){
            if(i+1==option){ // Option 1 to 12 is specific Month
                printf("\n\n\n");
                printf("\033[0;36m              *******************        \033[0m\n");
                printf("\033[0;34m              *                 *\033[0m\n");
                printf("\033[0;35m                 %s,%d      \033[0m\n",months[i],year);
                printf("\033[0;34m              *                 *\033[0m\n");
                printf("\033[0;36m              *******************        \033[0m");
            }
            if(i%2==0){
                Red();
            }
            else{
                Yellow();
            }

            if(option==0 || option==i+1){
                printf("\n\n\n------------------%s---------------------\n",months[i]);
            }

            if(option==0 || option==i+1){
                printf("\n   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n\n");
            }

            for(spaceCounter=1; spaceCounter<=weekDay; spaceCounter++){
                if(option==0 || option==i+1)printf("      ");// 6 space
            }
            totalDays=daysInMonth[i];
            for(int j=1; j<=totalDays; j++){
                if(option==13){
                    if(i+1==specificMonth && j==specificDate){
                        specificDay=weekDay;
                    }
                }
                else if(weekDay==5){
                    if(option==0 || option==i+1)printf("\033[0;37m%6d\033[0m",j);
                }
                else{
                    if(i%2==0){
                        Red();
                    }
                    else{
                        Yellow();
                    }
                    if(option==0 || option==i+1)printf("%6d",j);
                }
                weekDay++;
                if(weekDay>6){
                    if(option==0 || option==i+1)printf("\n");
                    weekDay=0;
                }
            }
            Reset();
        }
        if(specificDay!=-1){
            Green();
            printf("\nYour Required Day is : ");
            if(specificDay==0)printf("Sunday\n");
            if(specificDay==1)printf("Monday\n");
            if(specificDay==2)printf("Tuesday\n");
            if(specificDay==3)printf("Wednesday\n");
            if(specificDay==4)printf("Thursday\n");
            if(specificDay==5)printf("Friday\n");
            if(specificDay==6)printf("Saturday\n");
            Reset();
        }
        printf("\n\n\n");
        printf("Are You Need More Information?\n");
        Green();
        printf("1.Yes\n");
        Red();
        printf("0.No\n");
        Reset();
        scanf("%d",&lastCheck);
    }
    Red();
    printf("\nThank You.\n\n");
    Reset();
}


int main(){
    int c;
    while(1){
        Green();
        printf("Option:\n");
        Reset();
        Blue();
        printf("1.Calender\n");
        printf("2.Alarm Clock\n");
        printf("3.Exit\n");
        Reset();
        Yellow();
        printf("Enter Choice No : ");
        scanf("%d",&c);
        Reset();
        if(c==1){
            calender();
        }
        if(c==2){
            AlarmClock();
        }
        if(c<0 || c>2)break;
    }

    return 0;
}
