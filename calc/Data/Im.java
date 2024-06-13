package Data;

public class Im extends FieldElem
{
    double re;
    double im;

    public Im(double re, double im)
    {
        this.re = re;
        this.im = im;
    }

    public Im unit()
    {
        return new Im(1, 0);
    }

    public Im zero()
    {
        return new Im(0, 0);
    }

    public Im add(Im x)
    {
        return new Im(re + x.re, im + x.im);
    }

    public Im add(FieldElem x)
    {
        return add((Im) x);
    }

    public Im mult(Im x)
    {
        return new Im(re * x.re - im * x.im , re * x.im + im * x.re);
    }

    public Im mult(FieldElem x)
    {
        return mult((Im) x);   
    }

    public Im conj()
    {
        return new Im(re, -im);
    }

    public Im scale(double x)
    {
        return new Im(re * x, im * x);
    }

    public double absSquared()
    {
        return re * re + im * im;
    }

    public Im inv()
    {
        return new Im(re, -im).scale(absSquared());
    }

    public Im div(Im x)
    {
        return mult(x.inv());
    }

    public Im div(FieldElem x)
    {
        return div((Im) x);
    }

    public Im sub(Im x)
    {
        return new Im(re - x.re, im - x.im);
    }

    public Im sub(FieldElem x)
    {
        return sub((Im) x);
    }

    @Override
    public String toString()
    {
        return String.format("%.2f + %.2fi", re, im);
    }
}    

