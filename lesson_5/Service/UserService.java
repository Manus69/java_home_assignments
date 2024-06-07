package Service;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

import Data.User;

public class UserService {
    private final List<User> users;

    public UserService() {
        this.users = new ArrayList<>();
    }

    public void addUser(User user)
    {
        users.add(user);
    }

    public Optional<User> getById(int id)
    {
        return users.stream().filter(x -> x.getId() == id).findFirst();
    }

    public List<User> getAllUsers()
    {
        return users;
    }
}
