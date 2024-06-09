package Service;

import java.util.List;
import java.util.Optional;

public interface ServiceInterface<IdInterface>
{
    public void                     add(IdInterface item);
    public Optional<IdInterface>    getById(int id);
    List<IdInterface>               getAll();
}