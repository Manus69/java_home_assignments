import java.util.List;
import java.util.logging.Logger;

import data.Teacher;
import view.UserView;

public class TeacherView implements UserView<Teacher>{

    Logger logger = Logger.getLogger(Teacher.class.getName());

    @Override
    public void sendToConsole(List<Teacher> list)
    {
        for (Teacher t : list)
        {
            logger.info(t.toString());
        }
    }
}
