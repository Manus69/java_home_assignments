package Data;

public abstract class FieldElem
{
    public abstract FieldElem unit();
    public abstract FieldElem zero();
    public abstract FieldElem inv();
    public abstract FieldElem add(FieldElem x);
    public abstract FieldElem mult(FieldElem x);
    public abstract FieldElem div(FieldElem x);
    public abstract FieldElem sub(FieldElem x);
}
