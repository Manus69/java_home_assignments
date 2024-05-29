public class Program
{
    public static void main(String[] args)
    {
        Market market = new Market();

        market.add(new Customer("Bjarne", "shampoo"));
        market.add(new Customer("Ada", "trousers"));
        market.add(new Customer("Bertrand", "pipe tobacco"));

        System.out.println(market.updateGetStr());

        market.add(new Customer("John", "red car"));
        market.add(new Customer("Terry", "pet"));

        System.out.println(market.updateGetStr());

        market.add(new Customer("Brian", "plane ticket"));
        market.add(new Customer("Richard", "pepper"));

        System.out.println(market.updateGetStr());
        System.out.println(market.updateGetStr());

        System.out.println(market);
    }
}
    
