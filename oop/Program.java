public class Program
{
    private static Product findItem(HotDrinkVendingMachine vMachine, String[] args) throws Exception
    {
        String msg = "Invalid args";

        if (args.length == 1)
        {
            return vMachine.getProduct(args[0]);
        }
        if (args.length == 3)
        {
            return vMachine.getProduct(args[0], Integer.parseInt(args[1]), Integer.parseInt(args[2]));
        }

        throw new Exception(msg);
    }

    public static void main(String[] args)
    {
        HotDrinkVendingMachine vMachine = new HotDrinkVendingMachine();
        Product prod;

        vMachine.addProduct(new Drink("coke", 3, 300));
        vMachine.addProduct(new HotDrink("latte", 5, 300, 80));
        vMachine.addProduct(new Drink("vodka", 10, 500));
        vMachine.addProduct(new HotDrink("hot vodka", 10, 500, 80));
        vMachine.addProduct(new HotDrink("beer", 5, 500, 70));
        vMachine.addProduct(new Drink("water", 2, 1000));

        System.out.println(vMachine);

        try
        {
            prod = findItem(vMachine, args);
            System.out.println(prod == null ? "No item found" : prod);
        }
        catch (Exception ex)
        {
            System.out.println(ex);
        }
    }
}