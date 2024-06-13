package Calc;

import Data.FieldElem;

public interface ICalc<T extends FieldElem>
{
    void    load(T x);
    T       add()   throws Exception;
    T       sub()   throws Exception;
    T       mult()  throws Exception;
    T       div()   throws Exception;
    T       inv()   throws Exception;
}