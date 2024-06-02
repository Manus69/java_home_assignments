package service;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import data.Stream;
import data.StreamComparator;
import data.StudentGroup;

public class StreamService {
    private List<Stream> streams;

    public StreamService()
    {
        this.streams = new ArrayList<Stream>();
    }

    public void addStream(List<StudentGroup> groups)
    {
        streams.add(new Stream(groups));
    }

    public Stream getStream(int index)
    {
        return streams.get(index);
    }

    public List<Stream> getStreams()
    {
        return streams;
    }

    public void sort()
    {
        Collections.sort(streams, new StreamComparator());
    }
}
