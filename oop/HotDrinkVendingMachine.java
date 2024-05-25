import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class HotDrinkVendingMachine implements VendingMachine
{
    private List<Product> items;

    public HotDrinkVendingMachine(List<Product> items)
    {
        this.items = items;
    }

    public HotDrinkVendingMachine()
    {
        this(new ArrayList<Product>());
    }

    public Product getProduct(String name)
    {
        return items.stream().filter(x -> x.getName().equals(name)).findAny().orElse(null);
    }

    public HotDrink getProduct(String name, int volume, int temperature)
    {
        return (HotDrink) items.stream().
                filter(x -> x instanceof HotDrink && 
                        x.getName().equals(name) &&
                        ((HotDrink)x).getVolume() == volume && 
                        ((HotDrink)x).getTemp() == temperature).findAny().orElse(null);
    }

    public void addProduct(Product product)
    {
        this.items.add(product);
    }

    @Override
    public String toString()
    {
        String top = "Content:";
        String bot = "---------";
        
        return String.format("%s\n%s\n%s\n", top, this.items.stream().map(Object::toString).collect(Collectors.joining("\n")), bot);
    }
}