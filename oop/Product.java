
abstract public class Product
{
    private String name;
    private double cost;

    public Product(String name, double cost)
    {
        this.name = name;
        this.cost = cost;
    }

    public String getName()
    {
        return name;
    }

    public double getCost()
    {
        return cost;
    }

    public void setName(String name)
    {
        this.name = name;
    }

    public void setCost(double cost)
    {
        this.cost = cost;
    }

    @Override
    public String toString()
    {
        return String.format("Product {%s %.2f} ", this.name, this.cost);
    }
}