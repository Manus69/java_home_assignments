public class Drink extends Product
{
    private int volume;

    public Drink(String name, double cost, int volume)
    {
        super(name, cost);
        this.volume = volume;
    }

    public int getVolume()
    {
        return this.volume;
    }

    public void setVolume(int volume)
    {
        this.volume = volume;
    }

    @Override
    public String toString()
    {
        return String.format("Drink {%s %.2f %d} ", this.getName(), this.getCost(), this.volume);
    }
}
    
