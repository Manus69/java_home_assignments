import Data.Im;
import Behaviour.Command;
import Calc.*;
import Parser.*;

// what folders to create ?
// enum op ?

public class Program
{
    public static void main(String[] args)
    {
        try
        {
            Calc<Im> c = new Calc<>();
            c.load(new Im(1, 1));
            c.load(new Im(-1, 1));
            Im x = c.add();
            System.out.println(x);

            c.load(new Im(10, 1));
            c.load(new Im(10, -1));
            x = c.mult();
            System.out.println(x);
        }
        catch (Exception ex)
        {
            System.out.println("ex");
        }
    }
}
    
