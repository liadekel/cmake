#include <exec.h>
#include <stdio.h>
#include <libso/libsoh1.h>
#include <headero/headero1.h>
#include <headero/headero2.h>

int main(int argc, char *argv[]){
#ifdef TEST
    printf("Exec executable is running\n");
    print_num1("HEADER_DEFINITION", HEADER_DEFINITION);
#ifdef TEST_LIBSO
    printf("TEST_LIBSO is defined from libso\n");
#endif
    print_num1("HEADERO1", HEADERO1);
    print_num1("HEADERO2", HEADERO2);
#endif
}
