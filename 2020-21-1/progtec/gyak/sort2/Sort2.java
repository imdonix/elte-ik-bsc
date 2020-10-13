/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sort2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 *
 * @author bli
 */
public class Sort2 {

    public static <T extends Comparable> List<T> sort(List<T> list, int i, int j) {
        Collections.sort(list.subList(0, i), new ReverseComparator<T>());
        Collections.sort(list.subList(i, j + 1));
        Collections.sort(list.subList(j + 1, list.size()), new ReverseComparator<T>());
        return list;
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        ArrayList<Integer> list = new ArrayList<>(Arrays.asList(7, 2, 15, 8, 3, 6, 18, 97));
        System.out.println(sort(list, 3, 5));
    }
    
}
