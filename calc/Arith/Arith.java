package Arith;

public class Arith
{
    public static int gcd(int x, int y)
    {
        if (y == 0) return x;

        return gcd(y, x % y);
    }

    public static int lcm(int x, int y)
    {
        return x * y / gcd(x, y);
    }

}
    
