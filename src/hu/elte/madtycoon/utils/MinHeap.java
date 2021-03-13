package hu.elte.madtycoon.utils;

import java.util.Arrays;

@SuppressWarnings("unchecked")
public class MinHeap<T extends Comparable<T>>
{
    private int initCapacity;
    private T[] heap;
    private int length;

    public MinHeap(int capacity)
    {
        initCapacity = capacity;
        heap = (T[]) new Comparable[initCapacity];
        length = 0;
    }

    public void add(T value)
    {
        if (this.length >= heap.length - 1)
        {
            heap = this.resize();
        }

        length++;
        heap[length] = value;
        bubbleUp();
    }

    protected T rem()
    {
        if (isEmpty()) return null;

        T result = peek();

        swap(1, length);
        heap[length] = null;
        length--;

        bubbleDown();

        return result;
    }

    protected boolean isEmpty()
    {
        return length == 0;
    }

    private T peek()
    {
        if (isEmpty()) throw new IllegalStateException();
        return heap[1];
    }

    private T[] resize()
    {
        return Arrays.copyOf(heap, heap.length + initCapacity);
    }

    private void bubbleUp()
    {
        int index = length;
        while (hasParent(index) && (parent(index).compareTo(heap[index]) > 0))
        {
            swap(index, parentIndex(index));
            index = parentIndex(index);
        }

    }

    private void bubbleDown()
    {
        int index = 1;

        while (hasLeftChild(index))
        {

            int smaller = leftIndex(index);
            if (hasRightChild(index) && heap[leftIndex(index)].compareTo(heap[rightIndex(index)]) > 0)
            {
                smaller = rightIndex(index);
            }
            if (heap[index].compareTo(heap[smaller]) > 0)
            {
                swap(index, smaller);
            }
            else break;

            index = smaller;
        }
    }

    private boolean hasParent(int i) { return i > 1; }

    private int leftIndex(int i) { return i * 2; }

    private int rightIndex(int i) { return i * 2 + 1; }

    private boolean hasLeftChild(int i) { return leftIndex(i) <= length; }

    private boolean hasRightChild(int i) { return rightIndex(i) <= length; }

    private int parentIndex(int i) { return i / 2; }

    private T parent(int i) { return heap[parentIndex(i)]; }

    private void swap(int index1, int index2)
    {
        T temp = heap[index1];
        heap[index1] = heap[index2];
        heap[index2] = temp;
    }

    @Override
    public String toString()
    {
        String retval = "";
        for (T each : heap)
        {
            if (each != null) retval += each + " : ";
        }
        return retval + "\n";
    }

}