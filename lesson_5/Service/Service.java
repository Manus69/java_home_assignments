package Service;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.HashMap;

import Data.IdInterface;

public class Service<T extends IdInterface> implements ServiceInterface<T> {
    private final HashMap<Integer, T> map;

    public Service()
    {
        this.map = new HashMap<>();
    }

    @Override
    public void add(T item) {
        map.put(item.getId(), item);
    }

    @Override
    public Optional<T> getById(int id) {
        return Optional.ofNullable(map.get(id));
    }

    @Override
    public List<T> getAll() {
        return new ArrayList<>(map.values());
    }   
}
