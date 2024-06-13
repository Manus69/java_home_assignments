package Calc;

import Data.FieldElem;
import java.util.Stack;

public class Calc<T extends FieldElem> implements ICalc<T>
{
    private Stack<T> stack;
    
    public Calc()
    {
        stack = new Stack<T>();
    }
    
    public void load(T x)
    {
        stack.add(x);
    }

    public T add() throws Exception
    {
        T rhs = stack.pop();
        T lhs = stack.pop();

        return (T) lhs.add(rhs);
    }

    public T mult() throws Exception
    {
        T rhs = stack.pop();
        T lhs = stack.pop();

        return (T) lhs.mult(rhs);
    }

    public T sub() throws Exception
    {
        T rhs = stack.pop();
        T lhs = stack.pop();

        return (T) lhs.sub(rhs);
    }

    public T div() throws Exception
    {
        T rhs = stack.pop();
        T lhs = stack.pop();

        return (T) lhs.div(rhs);
    }

    public T inv() throws Exception
    {
        return (T) stack.pop().inv();
    }
}    

