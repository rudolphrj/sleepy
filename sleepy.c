#include <stdio.h>
#include <time.h>
#include <string.h>

void sleep(int wake_hr, int wake_min) {
    printf("lolz\n");
}

int mod_n(int num_mod, int n) {
    if (num_mod < n)
        return num_mod;
    else {
        while(num_mod >= n) {
            num_mod = num_mod % n;
            }
    }
    return num_mod;
}

void print_time(int hr, int min) {
    hr = mod_n(hr,24);
    min = mod_n(min,60);
    if (hr < 10 && min < 10)
        printf("0%d:0%d", hr, min);
    else if (hr < 10 || min < 10) {
        if (hr < 10) {
            printf("0%d:%d", hr, min);
        }
        if (min < 10) {
            printf("%d:0%d", hr, min);
        }
    }
    else
        printf("%d:%d", hr, min);
}



int main(int argc, char *argv[]) {
//    printf("Program name %s\n", argv[1]);
    time_t now = time(NULL);
    struct time {
        int hr;
        int min;
    };

    struct tm tm = *localtime(&now);
    struct time t1;
    struct time cyc;
    cyc.hr = 1;
    cyc.min = 30;

    if (argc == 2) {
    if (strcmp(argv[1], "-s") == 0) {
        printf("What time do you want to fall asleep? (HH:MM) ");
        scanf("%d:%d", &t1.hr, &t1.min);
        printf("\n");

        printf("If you want to fall asleep at ");
        print_time(t1.hr, t1.min);
        printf(", you should wake up at one of the following times:\n");

        print_time(t1.hr + 5, t1.min+30);
        printf(" for 3 cycles - 4 and a half hours of sleep.\n");
        print_time(t1.hr + 6, t1.min);
        printf(" for 4 cycles - 6 hours of sleep.\n");
        print_time(t1.hr+8, t1.min+30);
        printf(" for 5 cycles - 7 and a half hours of sleep.\n");
        print_time(t1.hr+9, t1.min);
        printf(" for 6 cycles - 9 hours of sleep.\n");
    }

    else {


        printf("Current time: ");
        print_time(tm.tm_hour, tm.tm_min);
        printf("\n");

        printf("What time do you want to wake up? (HH:MM) ");
        scanf("%d:%d", &t1.hr, &t1.min);
        printf("\n");

        printf("If you want to wake up at ");
        print_time(t1.hr, t1.min);
        printf(", you should go to sleep at one of the following times:\n");

        print_time(24 + (t1.hr - 4), 60+t1.min-30);
        printf(" for 3 cycles - 4 and a half hours of sleep.\n");
        print_time(24+(t1.hr-6), 60+t1.min-0);
        printf(" for 4 cycles - 6 hours of sleep.\n");
        print_time(24+(t1.hr-8), 60+t1.min-30);
        printf(" for 5 cycles - 7 and a half hours of sleep.\n");
        print_time(24+(t1.hr-9), 60+t1.min-00);
        printf(" for 6 cycles - 9 hours of sleep.\n");
    }
    }
else {


        printf("Current time: ");
        print_time(tm.tm_hour, tm.tm_min);
        printf("\n");

        printf("What time do you want to wake up? (HH:MM) ");
        scanf("%d:%d", &t1.hr, &t1.min);
        printf("\n");

        printf("If you want to wake up at ");
        print_time(t1.hr, t1.min);
        printf(", you should go to sleep at one of the following times:\n");

        print_time(24 + (t1.hr - 4), 60+t1.min-30);
        printf(" for 3 cycles - 4 and a half hours of sleep.\n");
        print_time(24+(t1.hr-6), 60+t1.min-0);
        printf(" for 4 cycles - 6 hours of sleep.\n");
        print_time(24+(t1.hr-8), 60+t1.min-30);
        printf(" for 5 cycles - 7 and a half hours of sleep.\n");
        print_time(24+(t1.hr-9), 60+t1.min-00);
        printf(" for 6 cycles - 9 hours of sleep.\n");
    }
    return 0;
}
