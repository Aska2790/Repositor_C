#include <stdio.h>
#include <cs50.h>

int main (void)
{
    printf("Minutes:");
    int minutes = get_int();
    printf("Bottles:%d%s", minutes*12, "\n");
}