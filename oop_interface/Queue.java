import java.util.ArrayDeque;
import java.util.Deque;
import java.util.stream.Collectors;
import java.util.Iterator;

public class Queue<T> implements QueueInterface<T>, Iterable<T>
{
    private final ArrayDeque<T> queue;

    public Queue()
    {
        this.queue = new ArrayDeque<T>();
    }

    public void pushBack(T item)
    {
        queue.add(item);
    }

    public T popFirst()
    {
        return this.queue.removeFirst();
    }

    public int size()
    {
        return queue.size();
    }

    public boolean empty()
    {
        return this.size() == 0;
    }

    @Override
    public Iterator<T> iterator()
    {
        return queue.iterator();
    }

    @Override
    public String toString()
    {
        return queue.stream().map(Object::toString).collect(Collectors.joining(", "));
    }
}