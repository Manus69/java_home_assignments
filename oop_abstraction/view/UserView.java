package view;

import data.User;

import java.util.List;

public interface UserView<T extends User>{
    void sendToConsole(List<T> list);
}
