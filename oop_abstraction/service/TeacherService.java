import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

import data.Teacher;
import service.UserService;

public class TeacherService implements UserService<Teacher>{
    
    private final List<Teacher> list;

    public TeacherService()
    {
        this.list = new ArrayList<>();
    }

    public List<Teacher> getAll()
    {
        return list;
    }

    public void create(String firstName, String secondName, String patronymic, LocalDate dateOfBirth)
    {
        Teacher t = new Teacher(firstName, secondName, patronymic, dateOfBirth);
        int id = list.size() > 0 ? list.stream().max(Comparator.comparing(Teacher::getTeacherId)).get().getTeacherId() : 0;

        t.setTeacherId(id);
        list.add(t);
    }

    public Teacher getByName(String firstName, String secondName)
    {
        return list.stream().filter(x -> x.getFirstName().equals(firstName) && x.getSecondName().equals(secondName)).findAny();
    }
}
