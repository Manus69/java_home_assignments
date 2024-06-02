package data;

import java.util.List;
import java.util.Iterator;

public class Stream implements Iterable<StudentGroup> {
    private List<StudentGroup> groups;

    public Stream(List<StudentGroup> groups)
    {
        this.groups = groups;
    }

    public int groupCount()
    {
        return groups.size();
    }

    @Override
    public Iterator<StudentGroup> iterator()
    {
        return groups.iterator();
    }
}
