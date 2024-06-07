package Data;

public class Teacher extends User {
    private int teacherId;

    public Teacher(String firstName, String secondName,
                   String lastName, String dateB, int teacherId) {
        super(firstName, secondName, lastName, dateB, teacherId);
    }

    public int getId() {
        return teacherId;
    }

    public void setId(int teacherId) {
        this.teacherId = teacherId;
    }

    @Override
    public String toString() {
        return "Teacher{" +
                "teacherId='" + teacherId + '\'' +
                ", firstName='" + super.getFirstName() + '\'' +
                ", secondName='" + super.getSecondName() + '\'' +
                ", patronymic='" + super.getLastName() + '\'' +
                ", dateOfBirth=" + super.getDateB() +
                '}';
    }
}