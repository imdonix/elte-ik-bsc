/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sort2;

import java.util.Comparator;

/**
 *
 * @author bli
 * @param <T>
 */
public class ReverseComparator<T extends Comparable> implements Comparator<T> {

    @Override
    public int compare(T t, T t1) {
        return t1.compareTo(t);
    }

}
