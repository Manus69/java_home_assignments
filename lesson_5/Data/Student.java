package Data;

public class Student extends User {
    public Student(String firstName, String secondName, String lastName,
                   String dateB, int studentId) {
        super(firstName, secondName, lastName, dateB, studentId);
    }

    public int getId() {
        return super.getId();
    }

    public void setId(int studentId) {
        super.setId(studentId);
    }

    @Override
    public String toString() {
        return String.format("Student {id : %d; name : %s}", this.getId(), this.getFirstName());
    }
}