package Service;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

import Data.*;

public class GroupService {
    private final List<Group> groups;

    public GroupService()
    {
        groups = new ArrayList<>();
    }

    public void addGroup(Group group)
    {
        groups.add(group);
    }

    public Optional<Group> getGroupById(int id)
    {
        return groups.stream().filter(x -> x.getId() == id).findFirst();
    }

    public List<Group> getGroupsByTeacherId(int id)
    {
        return groups.stream().filter(x -> x.getTeacher().getId() == id).collect(Collectors.toList());
    }
}
