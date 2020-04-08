package datastructures.immutable;

import datastructures.Month;
import static datastructures.Month.*;

public class SetOfMonths {
    private short data;

    private SetOfMonths(short data) {
        this.data = data;
    }

    public SetOfMonths add(Month month) {
        int pos = month.ordinal();
        // 000000001 << 3 -> 000001000
        int mask = (1 << pos);
        data |= mask;
        //data |= 1 << pos;
        return this;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("{");
        for (Month month : Month.values()) {
            int pos = month.ordinal();
            int mask = (1 << pos);

            // mask == 00000010
            // data == 00110110
            if ((data & mask) != 0) {
                sb.append(month);
                sb.append(",");
            }
        }
        sb.append("}");
        return sb.toString();
    }

    public static SetOfMonths empty() {
        return new SetOfMonths((short)0);
    }

/*
    public static SetOfMonths of(Month... months) {
        for (Month month : months) {
            //
        }
    }
*/

    public static void main(String[] args) {
        SetOfMonths set1 = empty();
        System.out.println(set1);
        set1.add(April).add(May);
        System.out.println(set1);
    }
}
