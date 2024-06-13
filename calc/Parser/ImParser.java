package Parser;

import Data.Im;

public class ImParser implements IParser<Im>
{
    private static char _I = 'i';

    private double _praseRe(String str) throws Exception
    {
        return Double.parseDouble(str);
    }

    private int _parseOp(String str) throws Exception
    {
        if (str.charAt(0) == '+') return 1;
        if (str.charAt(0) == '-') return -1;

        throw new Exception("Invalid op token");
    }

    private double _parseIm(String str) throws Exception
    {
        int idx = str.indexOf(_I);

        if (idx == -1) throw new Exception(String.format("%c expected", _I));

        return _praseRe(str.substring(0, idx - 1));
    }

    public Im parse(String str) throws Exception
    {
        String[] tokens = str.split(" ");

        if (tokens.length == 1) return new Im(_praseRe(tokens[0]), 0);
        if (tokens.length == 3) return new Im(_praseRe(tokens[0]), _parseOp(tokens[1]) * _parseIm(tokens[2]));

        throw new Exception("Invalid string");
    }
}    

