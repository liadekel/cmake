#include <stdio.h>
#include <sharedlibrary1.h>
#include <sharedlibrary2.h>


int print_num1(char *str, int num) {
    printf("print_num1: %s=%d\n",str, num);
    return 0;
}

int print_num2(char *str, int num) {
    printf("print_num2: %s=%d\n",str, num);
    return 0;
}
