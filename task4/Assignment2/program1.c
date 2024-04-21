#include <stdio.h>
#include <string.h>

struct Date {
    int day;
    int month;
    int year;
};

int is_valid_date(struct Date date) {
    if (date.month < 1 || date.month > 12) {
        return 0;
    }

    int max_days = 31;
    if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) {
        max_days = 30;
    } else if (date.month == 2) {

        if ((date.year % 4 == 0 && date.year % 100 != 0) || date.year % 400 == 0) {
            max_days = 29;
        } else {
            max_days = 28;
        }
    }

    if (date.day < 1 || date.day > max_days) {
        return 0;
    }

    return 1;
}


int comparing(struct Date date1, struct Date date2) {
    if (date1.year != date2.year) {
        return 0;
    }

    if (date1.month != date2.month) {
        return 0;
    }

    if (date1.day != date2.day) {
        return 0;
    }

    return 1;
}

int main() {
    char date_str1[11], date_str2[11];

    printf("Enter first date (DD-MM-YYYY): ");
    fgets(date_str1, sizeof(date_str1), stdin);
    date_str1[strcspn(date_str1, "\n")] = '\0';

    printf("Enter second date (DD-MM-YYYY): ");
    fgets(date_str2, sizeof(date_str2), stdin);
    date_str2[strcspn(date_str2, "\n")] = '\0';

    struct Date date1, date2;
    sscanf(date_str1, "%d-%d-%d", &date1.day, &date1.month, &date1.year);
    sscanf(date_str2, "%d-%d-%d", &date2.day, &date2.month, &date2.year);

    if (!is_valid_date(date1) || !is_valid_date(date2)) {
        printf("Invalid date format or date value. Please enter dates in DD-MM-YYYY format.\n");
        return 1;
    }

    int are_equal = comparing(date1, date2);
    if (are_equal) {
        printf("Dates are equal.\n");
    } else {
        printf("Dates are not equal.\n");
    }

    return 0;
}
