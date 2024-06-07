package View;

import java.util.stream.Collectors;

import Data.Group;

public class GroupView {
    public void printToConsole(Group group)
    {
        String str = String.format("%s : { %s }", 
                    group.getTeacher().toString(), 
                    group.getStudents().stream().map(Object::toString).collect(Collectors.joining(", ")));

        System.out.println(str);
    }
}
