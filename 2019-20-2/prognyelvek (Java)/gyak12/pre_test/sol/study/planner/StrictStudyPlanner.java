

package study.planner;

import java.util.Set;
import java.util.TreeSet;


public class StrictStudyPlanner extends StudyPlanner {
    @Override
    public int pageCountOf(String bookName) throws StudyException {
        Set<Integer> lineElems = bookToPages.get(bookName);
        if (lineElems == null) throw new StudyException("Book " + bookName + " is unknown");
        TreeSet<Integer> treeLineElems = new TreeSet<Integer>(lineElems);
        int min = treeLineElems.ceiling(Integer.MIN_VALUE);
        int max = treeLineElems.floor(Integer.MAX_VALUE);
        return max - min + 1;
    }

    @Override
    public boolean isStudied(String bookName, int page) throws StudyException {
        Set<Integer> lineElems = bookToPages.get(bookName);
        if (lineElems == null) throw new StudyException("Book " + bookName + " is unknown");
        TreeSet<Integer> treeLineElems = new TreeSet<Integer>(lineElems);
        int min = treeLineElems.ceiling(Integer.MIN_VALUE);
        int max = treeLineElems.floor(Integer.MAX_VALUE);
        return min <= page && page <= max;
    }

    @Override
    public boolean isStudied(String bookName, int from, int to) throws StudyException {
        Set<Integer> lineElems = bookToPages.get(bookName);
        if (lineElems == null) throw new StudyException("Book " + bookName + " is unknown");
        TreeSet<Integer> treeLineElems = new TreeSet<Integer>(lineElems);
        int min = treeLineElems.ceiling(Integer.MIN_VALUE);
        int max = treeLineElems.floor(Integer.MAX_VALUE);
        return min <= from && to <= max || from <= min && to >= min || from <= max && to >= max;
        // az is jó megoldás h min <= from && from <= max) || ((min <= to && to <= max    
    }
}

//
//       min                       max
//       __________________________
//  .. .....     ....          .........
