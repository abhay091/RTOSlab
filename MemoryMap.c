#include <stdio.h>
#include <malloc.h>
#include <alloca.h>

extern void afunct(void);

int bss_v;
int data_v = 42;

int main(int argc, char **argv)
{
    char *p, *h;

    printf("Text Locations - \n");
    printf("\tAddress of main - %p\n", main);
    printf("\tAddress of afunc - %p\n", afunct);

    printf("Stack Locations - \n");
    afunct();

    p = (char *)alloca(32);
    if (p != NULL)
    {
        printf("\tStart of alloca()'ed array - %p\n", p);
        printf("\tEnd of alloca()'ed array - %p\n", p + 31);
    }

    printf("Data Locations - \n");
    printf("\tAddress of data_var - %p\n", &data_v);

    printf("BSS Locations - \n");
    printf("\tAddress of bss_var - %p\n", &bss_v);

    printf("Heap Location - \n");
    h = (char *)malloc(100);
    if (h != NULL)
    {
        printf("\tInitial End of heap - %p\n", h);
        printf("\tNew End of heap - %p\n", h + 99);
    }
}

void afunct(void)
{
    static int lvl = 0;
    auto int stck_var;

    if (++lvl == 3)
        return;

    printf("\tStack level %d, address of stack_var - %p\n",
           lvl, &stck_var);
    afunct();
}
