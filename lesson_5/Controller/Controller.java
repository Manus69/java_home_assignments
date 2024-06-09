package Controller;

import Data.Group;
import Data.Student;
import Data.Teacher;
import Service.IdService;
import Service.Service;
import View.GroupView;
import View.UserView;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class Controller {
    private final Service<Student>  studentService;
    private final Service<Teacher>  teacherService;
    private final Service<Group>    groupService;
    private final UserView          userView;
    private final GroupView         groupView;

    public Controller()
    {
        studentService = new Service<Student>();
        teacherService = new Service<Teacher>();
        groupService = new Service<Group>();
        userView = new UserView();
        groupView = new GroupView();
    }

    public int createStudent(String firstName, String secondName, String lastName, String dateB)
    {
        int id = IdService.nextId();

        studentService.add(new Student(firstName, secondName, lastName, dateB, id));

        return id;
    }

    public Optional<Student> getStudentById(int id)
    {
        return studentService.getById(id);
    }

    public List<Student> getAllStudents()
    {
        return studentService.getAll();
    }

    public int createTeacher(String firstName, String secondName, String lastName, String dateB)
    {
        int id = IdService.nextId();

        teacherService.add(new Teacher(firstName, secondName, lastName, dateB, id));

        return id;
    }

    public Optional<Teacher> getTeacherById(int id)
    {
        return teacherService.getById(id);
    }

    public List<Teacher> getAllTeachers()
    {
        return teacherService.getAll();
    }

    public int createGroup(int teacherId, List<Integer> studentIds) throws Exception
    {
        int                 id = IdService.nextId();
        Optional<Teacher>   teacher;
        Optional<Student>   student;
        List<Student>       students = new ArrayList<>();

        teacher = getTeacherById(teacherId);
        if (! teacher.isPresent()) throw new Exception("No teacher with this id");

        for (int sid : studentIds)
        {
            student = getStudentById(sid);
            if (! student.isPresent()) throw new Exception("No student with this id");

            students.add(student.get());
        }

        groupService.add(new Group(teacher.get(), students, id));

        return id;
    }

    public Optional<Group> getGroupById(int id)
    {
        return groupService.getById(id);
    }

    public List<Group> getAllGroups()
    {
        return groupService.getAll();
    }

    public void printStudents()
    {
        for (Student s : studentService.getAll()) userView.printToConsole(s);
    }

    public void printTeachers()
    {
        for (Teacher t : teacherService.getAll()) userView.printToConsole(t);
    }

    public void printGroups()
    {
        for (Group g : groupService.getAll()) groupView.printToConsole(g);
    }

}