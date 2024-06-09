import Controller.*;

public class Main {
    public static void main(String[] args) {

        Controller controler = new Controller();
        
        controler.createStudent("sudent 0", null, null, null);
        controler.createStudent("student 1", null, null, null);
        controler.createTeacher("teacher 0", null, null, null);

        controler.printStudents();
        controler.printTeachers();
    }
}