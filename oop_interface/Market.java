public class Market implements MarketInterface
{
    private final Queue<CustomerInterface> queue;
    private final Queue<CustomerInterface> pending;
    private final Queue<CustomerInterface> served;

    public Market()
    {
        this.queue = new Queue<>();
        this.pending = new Queue<>();
        this.served = new Queue<>();
    }

    public void add(CustomerInterface customer)
    {
        this.queue.pushBack(customer);
    }

    public int queueSize()
    {
        return queue.size();
    }

    private void takeOrders()
    {
        while (! queue.empty())
        {
            pending.pushBack(queue.popFirst());
        }
    }

    private void serve()
    {
        CustomerInterface customer;

        while (! pending.empty())
        {
            customer = pending.popFirst();
            customer.serve();
            served.pushBack(customer);
        }
    }

    public void update()
    {
        serve();
        takeOrders();
    }

    public String updateGetInfo()
    {
        StringBuilder str = new StringBuilder();

        str.append("Taking orders from: ");
        for (CustomerInterface customer : queue)
        {
            str.append(customer.getName() + ", ");
        }

        str.append("\nServing: ");
        for (CustomerInterface customer : pending)
        {
            str.append(customer.demand() + " to ");
            str.append(customer.getName() + ", ");
        }

        str.append("\n");
        update();

        return str.toString();
    }

    @Override
    public String toString()
    {
        return String.format("Market queue: <%s>\nPending: <%s>\nServed: <%s>\n", queue, pending, served);
    }
}