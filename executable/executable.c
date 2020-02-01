#include <stdio.h>
#include <executable.h>
#include <headeronly/headeronly1.h>
#include <headeronly/headeronly2.h>
#include <sharedlibrary/sharedlibrary1.h>

int main(int argc, char *argv[]){
#ifdef TEST
    printf("Exec executable is running\n");
    print_num1("EXECUTALBE_HEADER_DEFINITION", EXECUTALBE_HEADER_DEFINITION);
#ifdef TEST_SHAREDLIBRARY
    printf("TEST_SHAREDLIBRARY is defined from sharedlibrary\n");
#endif
    print_num1("HEADERONLY1", HEADERONLY1);
    print_num1("HEADERONLY2", HEADERONLY2);
#endif
}
