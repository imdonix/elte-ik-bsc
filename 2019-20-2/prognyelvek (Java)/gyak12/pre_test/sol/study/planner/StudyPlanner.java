

package study.planner;

import java.util.Scanner;
import java.util.Map;
import java.util.Set;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Objects;
import java.util.LinkedList;
import java.util.Collections;


public class StudyPlanner implements Comparable<StudyPlanner> {
    Map<String, HashSet<Integer>> bookToPages; // adattag

    public void readPagesFromText(Scanner sc) throws StudyException { // param
        bookToPages = new HashMap<>();

        int lineCount = Integer.parseInt(sc.nextLine());

        for (int i = 0; i < lineCount; i++) { // i kezdő és végértéke
            String line = sc.nextLine();
            String[] split = line.split(" ");

            //if (split.length > 3)   throw new IllegalArgumentException("Data for book " + line + " is wrong");
            // figyelmen kívül hagyás
            if (split.length < 3) continue;

            int from = Integer.parseInt(split[0]);
            int to = Integer.parseInt(split[1]);
            String bookName = joinTexts(2, split);

            HashSet<Integer> lineElems = bookToPages.get(bookName);
            if (lineElems == null) lineElems = new HashSet<>();

            for (int j = from; j <= to; j++) {
                if (lineElems.contains(j)) throw new StudyException("Book " + bookName + " already contains page " + j);
                lineElems.add(j);
            }

            bookToPages.put(bookName, lineElems);
        }
    }

    private String joinTexts(int idx, String[] split) {
        StringBuilder retVal = new StringBuilder();
        retVal.append(split[2]);
        for (int i = 3; i < split.length; i++) {
            retVal.append(" "); // szóköz szeparátor
            retVal.append(split[i]);
        }
        return retVal.toString(); // toString()
    }

    public int getBookCount() {
        return bookToPages.size();
    }

    public int pageCountOf(String bookName) throws StudyException {
        Set<Integer> lineElems = bookToPages.get(bookName);
        if (lineElems == null) throw new StudyException("Book " + bookName + " is unknown");
        return lineElems.size();
    }

    public boolean isStudied(String bookName, int page) throws StudyException {
        Set<Integer> lineElems = bookToPages.get(bookName);
        if (lineElems == null) throw new StudyException("Book " + bookName + " is unknown");
        return lineElems.contains(page);
    }

    public boolean isStudied(String bookName, int from, int to) throws StudyException {
        Set<Integer> lineElems = bookToPages.get(bookName);
        if (lineElems == null) throw new StudyException("Book " + bookName + " is unknown");
        boolean result = false;
        for (int i = from; i <= from && !result; ++i) {
            result = lineElems.contains(i);
        }
        return result;
    }

    @Override
    public boolean equals(Object that) {
        if (that == null)
            return false;
        if (that == this)
            return true;
        if (that instanceof StudyPlanner) {
            StudyPlanner sp = (StudyPlanner)that;
            return bookToPages.equals(sp.bookToPages);
        }
        else return false;
    }

    @Override
    public int hashCode() {
        return Objects.hash(bookToPages);
    }

    @Override
    public int compareTo(StudyPlanner that) {
        if (that == null) throw new IllegalArgumentException();
        if (that == this) return 0;

        Set<String> this_books = this.bookToPages.keySet();
        Set<String> that_books = that.bookToPages.keySet();
        int this_pages = 0, that_pages = 0;

        try {
            for (String book : this_books) {
                this_pages += this.pageCountOf(book);
            }

            for (String book : that_books) {
                that_pages += that.pageCountOf(book);
            }
        }
        catch (StudyException e) {
            throw new IllegalArgumentException("logic error");
        }

        return Integer.signum(this_pages - that_pages);
    }
}
