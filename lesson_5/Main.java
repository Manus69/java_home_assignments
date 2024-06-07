import Controller.*;

public class Main {
    public static void main(String[] args) {

        Controller controler = new Controller();
        controler.createStudent("1", "1","1","1");
        controler.createStudent("2", "2","2","2");
        controler.getAllStudents();
        controler.createStudent("3", "3","3","3");
        controler.createStudent("4", "4","4","4");
        controler.getAllStudents();
    }
}