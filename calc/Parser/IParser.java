package Parser;

public interface IParser<T>
{
    T parse(String str) throws Exception;
}
