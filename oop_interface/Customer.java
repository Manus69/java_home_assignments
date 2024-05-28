public class Customer extends Person implements CustomerInterface
{
    private String  demand;
    private boolean satisfied;

    public Customer(String name, String demand)
    {
        super(name);
        this.demand = demand;
        this.satisfied = false;
    }

    public String getName()
    {
        return super.getName();
    }

    public String demand()
    {
        return demand;
    }

    public boolean satisfied()
    {
        return this.satisfied;
    }

    public void serve()
    {
        this.satisfied = true;
    }

    @Override
    public String toString()
    {
        return String.format("Customer: {name: %s, demand: %s, satisfied: %b}", this.getName(), this.demand, this.satisfied);
    }
}