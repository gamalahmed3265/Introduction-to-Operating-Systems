/********* t.c file ********/
#include <stdio.h>
int sub(int a, int b, int c, int d, int e, int f, int g, int h)
{
    int u, v, w;
    u = 9;
    v = 10;
    w = 11;
    return a + g + u + v; // use first and extra parameter, locals
}
int main()
{
    int a, b, c, d, e, f, g, h, i;
    a = 1;
    b = 2;
    c = 3;
    d = 4;
    e = 5;
    f = 6;
    g = 7;
    h = 8;
    i = sub(a, b, c, d, e, f, g, h);

    int sum = mysum(123,456);

}
