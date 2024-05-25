package ru.gb.oseminar;

public interface VendingMachine {
    Product getProduct(String name) throws IllegalStateException;
}
