package Data;

public class Teacher extends User {
    public Teacher(String firstName, String secondName,
                   String lastName, String dateB, int teacherId) {
        super(firstName, secondName, lastName, dateB, teacherId);
    }

    public int getId() {
        return super.getId();
    }

    public void setId(int teacherId) {
        super.setId(teacherId);
    }

    @Override
    public String toString() {
        return String.format("Teacher {id : %d; name : %s}", this.getId(), this.getFirstName());
    }
}