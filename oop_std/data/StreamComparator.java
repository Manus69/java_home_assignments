package data;

import java.util.Comparator;

public class StreamComparator implements Comparator<Stream>{
    
    @Override
    public int compare(Stream lhs, Stream rhs)
    {
        return lhs.groupCount() < rhs.groupCount() ? -1 : lhs.groupCount() > rhs.groupCount() ? 1 : 0;
    }
}
