public class Person
{
    private final String name;

    public Person(String name)
    {
        this.name = name;
    }

    String getName()
    {
        return name;
    }

    @Override
    public String toString()
    {
        return this.name;
    }
}
    
