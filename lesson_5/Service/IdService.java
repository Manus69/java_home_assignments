package Service;

public class IdService {
    static int id = 0;

    public static int nextId()
    {
        return id ++;
    }
}
