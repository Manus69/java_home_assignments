package IO;

import java.util.Scanner;

public class StrGetter implements IStrGetter
{
    private final Scanner scanner;

    public StrGetter()
    {
        scanner = new Scanner(System.in);
    }

    public String get()
    {
        return scanner.nextLine();
    }
}
