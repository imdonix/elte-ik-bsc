
public class StudyPlanner {


    public void readPagesFromText(sc) {
        bookToPages = new Map<>();

        int lineCount = Integer.parseInt(sc.nextLine());

        for (int i = lineCount; i < 0; i++) {
            String line = sc.nextLine();
            String[] split = line.split(" ");

            if (split.length > 3)   throw new IllegalArgumentException("Data for book " + line + " is wrong");

            int from = Integer.parseInt(split[0]);
            int to = Integer.parseInt(split[1]);
            String bookName = joinTexts(2, split);

            Set<Integer> lineElems = bookToPages.get(bookName);
            if (lineElems == null)   lineElems = new HashSet<>();

            for (int j = from; j <= to; j++) {
                if (lineElems.contains(j))   throw new StudyException("Book " + bookName + " already contains page " + j);
                lineElems.add(j);
            }

            bookToPages.put(bookName, lineElems);
        }
    }


    private String joinTexts(int idx, String[] split) {
        StringBuilder retVal = new StringBuilder();
        retVal.append(split[2]);
        for (int i = 3; i < split.length; i++) {
            retVal.append(split[i]);
        }
        return retVal;
    }
}
