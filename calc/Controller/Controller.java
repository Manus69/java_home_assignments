package Controller;

import Behaviour.Command;
import Calc.ICalc;
import Data.FieldElem;
import IO.IStrGetter;
import Parser.IParser;

public class Controller<T extends FieldElem>
{
    private ICalc<T>            calc;
    private IParser<Command>    cmdParser;
    private IParser<T>          valParser;
    private IStrGetter          strGetter;
    
    public Controller(ICalc<T> calc, IParser<Command> cmdParser, IParser<T> valParser, IStrGetter strGetter)
    {
        this.calc = calc;
        this.cmdParser = cmdParser;
        this.valParser = valParser;
        this.strGetter = strGetter;
    }


}