#include <iostream>

int GCD1(int a, int b)
{
    if (a < b) return GCD1(a, b - a);
    if (a > b) return GCD1(a - b, b);

    return a;
}

int GCD2(int a, int b)
{
    while (a != b)
    {
        if (a < b) b -= a;
        if (a > b) a -= b;
    }

    return a;
}

int LCM(int a, int b)
{
    int gcd = GCD2(a, b);

    return a * b / gcd;
}

int main()
{
    using namespace std;

    constexpr int a = 13, b = 19;

    // greatest common devide
    int gcd1 = GCD1(a, b);
    cout << "GCD1(" << a << ", " << b << ") = " << gcd1 << endl;

    int gcd2 = GCD2(a, b);
    cout << "GCD2(" << a << ", " << b << ") = " << gcd2 << endl;

    // least common multiple
    int lcm = LCM(a, b);
    cout << "LCM(" << a << ", " << b << ") = " << lcm << endl;
}