int x = 5;
int y;
static int a = 7;

int foo(void)
{
    return x += bar(y);
}

static int goo(int w)
{
    return a += w;
}

