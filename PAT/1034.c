# include <stdio.h>

//化简分数
void simplify(long *a, long *b)
{
    int sign = (*a >= 0) ? 1 : 0;
    long x = *a, y = *b;
    //若符号为负号，则取其相反数
    if (!sign)
        x = -x;
    for (int i=2; i <= x && i <= y; i++) {
        if (x % i || y % i)
            continue;
        x /= i;
        y /= i;
        i--;
    }
    *a = (sign) ? x : -x;
    *b = y;
}

//假分数转为真分数
void convert(long *a, long *b, long *c)
{
    *c = *a / *b;
    *a %= *b;
    //负号前置
    if (*c != 0 && *a < 0) {
        *a = -*a;
     //   *c = -*c;
    }
}

void pr_num(long a, long b, long c)
{
    convert(&a, &b, &c);
    if (c < 0 || a < 0)
        printf("(");
    if (c)
        printf("%ld", c);
    if (c && a)
        putchar(' ');
    if (a)
        printf("%ld/%ld", a, b);
    if (c < 0 || a < 0)
        printf(")");
    if (!c && !a)
        printf("0");
}

void display(long a1, long b1, long a2, long b2, char sign)
{
    long c1 = 0, c2 = 0;
    //输出等号左边
    pr_num(a1, b1, c1);
    printf(" %c ", sign);

    //输出等号右边
    pr_num(a2, b2, c2);
    printf(" = ");
}

int main()
{
    long a1, b1, a2, b2;
    scanf("%ld/%ld %ld/%ld", &a1, &b1, &a2, &b2);

    simplify(&a1, &b1);
    simplify(&a2, &b2);
    //符号，正数为1，负数为0;
    int sign_1 = (a1 >= 0) ? 1 : 0;
    int sign_2 = (a2 >= 0) ? 1 : 0;
    //公共的分母数
    int b_both = b1 * b2;
    long a3, b3, c3;

    //加
    display(a1, b1, a2, b2, '+');
    a3 = a1 * b2 + a2 * b1;
    b3 = b_both;
    c3 = 0;
    simplify(&a3, &b3);
    pr_num(a3, b3, c3);
    putchar('\n');

    //减
    display(a1, b1, a2, b2, '-');
    a3 = a1 * b2 - a2 * b1;
    b3 = b_both;
    c3 = 0;
    simplify(&a3, &b3);
    pr_num(a3, b3, c3);
    putchar('\n');

    //乘
    display(a1, b1, a2, b2, '*');
    a3 = a1 * a2;
    b3 = b1 * b2;
    c3 = 0;
    simplify(&a3, &b3);
    pr_num(a3, b3, c3);
    putchar('\n');

    //除
    display(a1, b1, a2, b2, '/');
    //除数为0
    if (!a2) {
        puts("Inf");
        return 0;
    }
    a3 = a1 * b2;
    b3 = b1 * a2;
    //负号移到分子上
    if (b3 < 0) {
        a3 = -a3;
        b3 = -b3;
    }
    c3 = 0;
    simplify(&a3, &b3);
    pr_num(a3, b3, c3);
    putchar('\n');

    return 0;
}