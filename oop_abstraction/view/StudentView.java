package view;

import Student;
import StudentGroup;

import java.util.List;
import java.util.logging.Logger;

public class StudentView implements UserView<Student>{

    Logger logger = Logger.getLogger(StudentView.class.getName());

    @Override
    public void sendToConsole(List<Student> students) {
        for(Student user: students){
            logger.info(user.toString());
        }
    }

    public void sendToConsoleUserGroup(StudentGroup studentGroup){
        logger.info(studentGroup.toString());
    }

}
