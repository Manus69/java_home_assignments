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

    public void create(String firstName, String secondName, String patronymic, LocalDate dateOfBirth)
    {
        service.create(firstName, secondName, patronymic, dateOfBirth);
        view.sendToConsole(service.getAll());
    }

    public Teacher getByName(String firstName, String secondName)
    {
        return service.getByName(firstName, secondName);
    }
}
