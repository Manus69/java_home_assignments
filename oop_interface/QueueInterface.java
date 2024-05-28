public interface QueueInterface<T>
{
    void    pushBack(T item);
    T       popFirst();
}