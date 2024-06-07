package Controller;

import Data.User;
import Data.Group;
import Data.Student;
import Data.Teacher;
import Service.UserService;
import Service.GroupService;
import Service.IdService;
import View.UserView;

import java.util.List;
import java.util.Optional;

public class Controller {
    private final UserService   studentService;
    private final UserService   teacherService;
    private final GroupService  groupService;
    private final UserView      userView;

    //create student, teacher, group
    // print all students, teachers ?

    public Controller()
    {
        studentService = new UserService();
        teacherService = new UserService();
        groupService = new GroupService();
        userView = new UserView();
    }

    public Student createStudent(String firstName, String secondName, String lastName, String dateB)
    {
        Student student = new Student(firstName, secondName, lastName, dateB, IdService.nextId());

        studentService.addUser(student);

        return student;
    }

    public Teacher createTeacher(String firstName, String secondName, String lastName, String dateB)
    {
        Teacher teacher = new Teacher(firstName, secondName, lastName, dateB, IdService.nextId());

        teacherService.addUser(teacher);

        return teacher;
    }

    public Group createGroup(Teacher teacher, List<Student> students)
    {
        Group group = new Group(teacher, students, IdService.nextId());

        groupService.addGroup(group);

        return group;
    }

    public Student getStudentById(int id) throws Exception
    {
        Optional<User> user = studentService.getById(id);
        if (user.isPresent()) return (Student) user.get();

        throw new Exception("No student with this id");
    }

    public Teacher getTeacherById(int id) throws Exception
    {
        Optional<User> user = teacherService.getById(id);
        if (user.isPresent()) return (Teacher) user.get();

        throw new Exception("No teacher with this id");
    }

    public Group getGroupById(int id) throws Exception
    {
        Optional<Group> group = groupService.getGroupById(id);
        if (group.isPresent()) return group.get();

        throw new Exception("No group with this id");
    }

    public List<Group> getGroupsByTeacherId(int id)
    {
        return groupService.getGroupsByTeacherId(id);
    }

    private void print(List<User> users)
    {
        for (User u : users) userView.printToConsole(u);
    }

    public void printStudents()
    {
        print(studentService.getAllUsers());
    }

    public void printTeachers()
    {
        print(teacherService.getAllUsers());
    }

    public void printGroups()
    {

    }

}