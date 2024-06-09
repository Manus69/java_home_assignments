package Data;

import java.util.List;

public class Group implements IdInterface{
    private Teacher         teacher;
    private List<Student>   students;
    private int             id;

    public Group(Teacher teacher, List<Student> students, int id)
    {
        this.teacher = teacher;
        this.students = students;
        this.id = id;
    }

    public int getId()
    {
        return id;
    }

    public Teacher getTeacher()
    {
        return teacher;
    }

    public List<Student> getStudents()
    {
        return students;
    }

    public void setTeacher(Teacher teacher)
    {
        this.teacher = teacher;
    }

    public void setStudents(List<Student> students)
    {
        this.students = students;
    }

    public void addStudent(Student student)
    {
        students.add(student);
    }
}
