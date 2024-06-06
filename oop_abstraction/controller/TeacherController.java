import java.time.LocalDate;

import controller.UserController;
import data.Teacher;

public class TeacherController implements UserController <Teacher>{
    private final TeacherService service;
    private final TeacherView view;

    public TeacherController()
    {
        this.service = new TeacherService();
        this.view = new TeacherView();
    }

    public void createTeacher(String firstName, String secondName, String patronymic, LocalDate dateOfBirth)
    {
        service.create(firstName, secondName, patronymic, dateOfBirth);
    }

    public Teacher getTeacherByName(String firstName, String secondName)
    {
        return service.getByName(firstName, secondName);
    }

    public Teacher getTeacherById(long id)
    {
        return service.getById(id);
    }

    public void editTeacher(long id, String firstName, String secondName, String patronymic, LocalDate dateOfBirth) throws Exception
    {
        Teacher tchr = this.getTeacherById(id);
        
        if (tchr == null) throw new Exception("No teacher with this id");

        tchr.edit(firstName, secondName, patronymic, dateOfBirth);
    }

    public void displayTeachers()
    {
        view.sendToConsole(service.getAll());
    }
}
