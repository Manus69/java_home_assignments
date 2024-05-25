public interface VendingMachine
{
    Product getProduct(String name);
    void    addProduct(Product product);
}