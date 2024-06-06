package controller;

import data.User;

import java.time.LocalDate;

public interface UserController<T extends User>{
    void createTeacher(String firstName, String secondName, String patronymic, LocalDate dateOfBirth);
}
