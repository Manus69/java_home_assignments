import java.util.Arrays;

import Controller.*;

public class Main {
    public static void main(String[] args) {

        Controller controller = new Controller();
        
        try
        {
            controller.createStudent("student 0", null, null, null);
            controller.createStudent("student 1", null, null, null);
            controller.createStudent("student 2", null, null, null);
            controller.createStudent("student x", null, null, null);

            controller.createTeacher("teacher 0", null, null, null);
            controller.createTeacher("teacher of something", null, null, null);

    
            controller.createGroup(4, Arrays.asList(0, 1));
            controller.createGroup(4, Arrays.asList(1, 2, 3));
            controller.createGroup(5, Arrays.asList(3));

            controller.printGroups();
        }
        catch (Exception ex)
        {
            System.out.println(ex.getMessage());
        }
    }
}