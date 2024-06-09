package View;

import java.util.stream.Collectors;

import Data.Group;

public class GroupView {
    public void printToConsole(Group group)
    {
        String str = String.format("Group id: %d\n%s : { %s }",
                    group.getId(), 
                    group.getTeacher().toString(), 
                    group.getStudents().stream().map(Object::toString).collect(Collectors.joining(", ")));

        System.out.println(str);
    }
}
