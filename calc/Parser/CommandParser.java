package Parser;

import java.util.HashMap;
import java.util.Map;

import Behaviour.*;

public class CommandParser implements IParser<Command>
{
    private static class CommandStr
    {
        private static Map<Command, String> _map = new HashMap<>()
        {{
            put(Command.ADD, "+");
            put(Command.MULT, "*");
            put(Command.SUB, "-");
            put(Command.DIV, "/");
            put(Command.INV, "-1");
            put(Command.KILL, "Q");
        }};

        public static String get(Command cmd)
        {
            return _map.get(cmd);
        }
    }

    public Command parse(String str) throws Exception
    {
        str = str.trim();

        if (str.equals(CommandStr.get(Command.ADD)))    return Command.ADD;
        if (str.equals(CommandStr.get(Command.DIV)))    return Command.DIV;
        if (str.equals(CommandStr.get(Command.INV)))    return Command.INV;
        if (str.equals(CommandStr.get(Command.KILL)))   return Command.KILL;
        if (str.equals(CommandStr.get(Command.MULT)))   return Command.MULT;
        if (str.equals(CommandStr.get(Command.SUB)))    return Command.SUB;

        throw new Exception("Invalid command");
    }
}
    
