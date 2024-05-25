public class HotDrink extends Drink
{
    private int temp;
    
    public HotDrink(String name, double cost, int volume, int temp)
    {
        super(name, cost, volume);
        this.temp = temp;
    }
    
    public int getTemp()
    {
        return this.temp;
    }

    public void setTemp(int temp)
    {
        this.temp = temp;
    }

    @Override
    public String toString()
    {
        return String.format("HotDrink {%s %.2f %d %d} ", this.getName(), this.getCost(), this.getVolume(), this.temp);
    }
}
    
