int x = 3;
int y = -1;
int w;

static int z;
static int a = 7;

int foo(void)
{
    return x += z;
}

int goo(int w)
{
    return a += w;
}

int main(void)
{
    int b = foo();
    return goo(b + x + y + w) * z;
}

