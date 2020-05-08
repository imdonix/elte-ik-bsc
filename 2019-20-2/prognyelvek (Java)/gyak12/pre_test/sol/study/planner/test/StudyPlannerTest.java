

package study.planner.test;

import static org.junit.Assert.*;
import org.junit.Test;

import java.util.Scanner;

import study.planner.StudyPlanner;
import study.planner.StrictStudyPlanner;
import study.planner.StudyException;


public class StudyPlannerTest {
    @Test
    public void noLines() throws StudyException {
        StringBuilder sb = new StringBuilder();
        sb.append("0");

        Scanner sc = new Scanner(sb.toString());
        StudyPlanner sp = new StudyPlanner();
        sp.readPagesFromText(sc);
        assertEquals(0, sp.getBookCount());
    }

    @Test
    public void exampleBookCount() throws StudyException {
        StringBuilder sb = new StringBuilder();
        sb.append("4");
        sb.append(System.lineSeparator());
        sb.append("10 20 Programozasi Nyelvek Java");
        sb.append(System.lineSeparator());
        sb.append("150 190 Analizis");
        sb.append(System.lineSeparator());
        sb.append("20 130 Analizis");
        sb.append(System.lineSeparator());
        sb.append("55 78 Programozasi Nyelvek Java");

        Scanner sc = new Scanner(sb.toString());
        StudyPlanner sp = new StudyPlanner();
        sp.readPagesFromText(sc);
        assertEquals(2, sp.getBookCount());
    }

    @Test
    public void examplePageCount_Analysis() throws StudyException {
        StringBuilder sb = new StringBuilder();
        sb.append("4");
        sb.append(System.lineSeparator());
        sb.append("10 20 Programozasi Nyelvek Java");
        sb.append(System.lineSeparator());
        sb.append("150 190 Analizis");
        sb.append(System.lineSeparator());
        sb.append("20 130 Analizis");
        sb.append(System.lineSeparator());
        sb.append("55 78 Programozasi Nyelvek Java");

        Scanner sc = new Scanner(sb.toString());
        StudyPlanner sp = new StudyPlanner();
        sp.readPagesFromText(sc);
        assertEquals(152, sp.pageCountOf("Analizis"));
    }

    @Test
    public void examplePageCount_Java() throws StudyException {
        StringBuilder sb = new StringBuilder();
        sb.append("4");
        sb.append(System.lineSeparator());
        sb.append("10 20 Programozasi Nyelvek Java");
        sb.append(System.lineSeparator());
        sb.append("150 190 Analizis");
        sb.append(System.lineSeparator());
        sb.append("20 130 Analizis");
        sb.append(System.lineSeparator());
        sb.append("55 78 Programozasi Nyelvek Java");

        Scanner sc = new Scanner(sb.toString());
        StudyPlanner sp = new StudyPlanner();
        sp.readPagesFromText(sc);
        assertEquals(35, sp.pageCountOf("Programozasi Nyelvek Java"));
    }

    @Test(expected = StudyException.class)
    public void missingBook() throws StudyException {
        StringBuilder sb = new StringBuilder();
        sb.append("4");
        sb.append(System.lineSeparator());
        sb.append("10 20 Programozasi Nyelvek Java");
        sb.append(System.lineSeparator());
        sb.append("150 190 Analizis");
        sb.append(System.lineSeparator());
        sb.append("20 130 Analizis");
        sb.append(System.lineSeparator());
        sb.append("55 78 Programozasi Nyelvek Java");

        Scanner sc = new Scanner(sb.toString());
        StudyPlanner sp = new StudyPlanner();
        sp.readPagesFromText(sc);
        sp.pageCountOf("MissingBook");
    }

    @Test
    public void exc2_TC1() throws StudyException {
        StringBuilder sb = new StringBuilder();
        sb.append("4");
        sb.append(System.lineSeparator());
        sb.append("10 20 Programozasi Nyelvek Java");
        sb.append(System.lineSeparator());
        sb.append("150 190 Analizis");
        sb.append(System.lineSeparator());
        sb.append("20 130 Analizis");
        sb.append(System.lineSeparator());
        sb.append("55 78 Programozasi Nyelvek Java");

        Scanner sc = new Scanner(sb.toString());
        StudyPlanner sp = new StudyPlanner();
        sp.readPagesFromText(sc);
        assertFalse(sp.isStudied("Analizis", 140));
        assertTrue(sp.isStudied("Analizis", 160));
        assertFalse(sp.isStudied("Analizis", 140, 200));
    }

    @Test
    public void exc2_TC2() throws StudyException {
        StringBuilder sb = new StringBuilder();
        sb.append("4");
        sb.append(System.lineSeparator());
        sb.append("10 20 Programozasi Nyelvek Java");
        sb.append(System.lineSeparator());
        sb.append("150 190 Analizis");
        sb.append(System.lineSeparator());
        sb.append("20 130 Analizis");
        sb.append(System.lineSeparator());
        sb.append("55 78 Programozasi Nyelvek Java");

        Scanner sc = new Scanner(sb.toString());
        StudyPlanner sp = new StrictStudyPlanner();
        sp.readPagesFromText(sc);
        assertTrue(sp.isStudied("Analizis", 141, 149));
        assertTrue(sp.isStudied("Analizis", 140, 200));
    }

    @Test
    public void exc2_TC3() throws StudyException {
        StringBuilder sb = new StringBuilder();
        sb.append("4");
        sb.append(System.lineSeparator());
        sb.append("10 20 Programozasi Nyelvek Java");
        sb.append(System.lineSeparator());
        sb.append("150 190 Analizis");
        sb.append(System.lineSeparator());
        sb.append("20 130 Analizis");
        sb.append(System.lineSeparator());
        sb.append("55 78 Programozasi Nyelvek Java");

        Scanner sc = new Scanner(sb.toString());
        StrictStudyPlanner sp = new StrictStudyPlanner();
        sp.readPagesFromText(sc);
        assertEquals(171, sp.pageCountOf("Analizis"));
    }

    @Test
    public void exc2_TC4() throws StudyException {
        StringBuilder sb = new StringBuilder();
        sb.append("4");
        sb.append(System.lineSeparator());
        sb.append("10 20 Programozasi Nyelvek Java");
        sb.append(System.lineSeparator());
        sb.append("150 190 Analizis");
        sb.append(System.lineSeparator());
        sb.append("20 130 Analizis");
        sb.append(System.lineSeparator());
        sb.append("55 78 Programozasi Nyelvek Java");

        Scanner sc = new Scanner(sb.toString());
        StrictStudyPlanner sp = new StrictStudyPlanner();
        sp.readPagesFromText(sc);
        assertEquals(69, sp.pageCountOf("Programozasi Nyelvek Java"));
    }

    @Test
    public void exc2_TC5() throws StudyException {
        StringBuilder sb = new StringBuilder();
        sb.append("4");
        sb.append(System.lineSeparator());
        sb.append("10 20 Programozasi Nyelvek Java");
        sb.append(System.lineSeparator());
        sb.append("150 190 Analizis");
        sb.append(System.lineSeparator());
        sb.append("20 130 Analizis");
        sb.append(System.lineSeparator());
        sb.append("55 78 Programozasi Nyelvek Java");

        Scanner sc = new Scanner(sb.toString());
        StrictStudyPlanner sp = new StrictStudyPlanner();
        sp.readPagesFromText(sc);
        assertFalse(sp.isStudied("Analizis", 19));
        assertTrue(sp.isStudied("Analizis", 140));
        assertTrue(sp.isStudied("Analizis", 135));
        assertTrue(sp.isStudied("Analizis", 140, 145));
        assertTrue(sp.isStudied("Analizis", 189, 195));
    }

    @Test
    public void studyDifferently() throws StudyException {
        StringBuilder sb = new StringBuilder();
        sb.append("6");
        sb.append(System.lineSeparator());
        sb.append("67 78 Programozasi Nyelvek Java");
        sb.append(System.lineSeparator());
        sb.append("10 20 Programozasi Nyelvek Java");
        sb.append(System.lineSeparator());
        sb.append("150 190 Analizis");
        sb.append(System.lineSeparator());
        sb.append("20 123 Analizis");
        sb.append(System.lineSeparator());
        sb.append("55 66 Programozasi Nyelvek Java");
        sb.append(System.lineSeparator());
        sb.append("124 130 Analizis");

        Scanner sc = new Scanner(sb.toString());
        StudyPlanner sp = new StudyPlanner();
        sp.readPagesFromText(sc);
        assertEquals(2, sp.getBookCount());
        assertEquals(152, sp.pageCountOf("Analizis"));
        assertEquals(35, sp.pageCountOf("Programozasi Nyelvek Java"));
        assertFalse(sp.isStudied("Analizis", 140));
        assertTrue(sp.isStudied("Analizis", 160));
        assertFalse(sp.isStudied("Analizis", 140, 200));

        sb.setLength(0);
        sb.append("4");
        sb.append(System.lineSeparator());
        sb.append("10 20 Programozasi Nyelvek Java");
        sb.append(System.lineSeparator());
        sb.append("150 190 Analizis");
        sb.append(System.lineSeparator());
        sb.append("20 130 Analizis");
        sb.append(System.lineSeparator());
        sb.append("55 78 Programozasi Nyelvek Java");

        Scanner sc2 = new Scanner(sb.toString());
        StudyPlanner sp2 = new StudyPlanner();
        sp2.readPagesFromText(sc2);

        assertTrue(sp.equals(sp2));
        assertTrue(sp2.equals(sp));
    }

    @Test
    public void exc4_TC1() throws StudyException {
        StringBuilder sb = new StringBuilder();
        sb.append("6");
        sb.append(System.lineSeparator());
        sb.append("67 78 Programozasi Nyelvek Java");
        sb.append(System.lineSeparator());
        sb.append("10 20 Programozasi Nyelvek Java");
        sb.append(System.lineSeparator());
        sb.append("150 190 Analizis");
        sb.append(System.lineSeparator());
        sb.append("20 123 Analizis");
        sb.append(System.lineSeparator());
        sb.append("55 66 Programozasi Nyelvek Java");
        sb.append(System.lineSeparator());
        sb.append("124 130 Analizis");

        Scanner sc = new Scanner(sb.toString());
        StudyPlanner sp = new StudyPlanner();
        sp.readPagesFromText(sc);

        sb.setLength(0);
        sb.append("4");
        sb.append(System.lineSeparator());
        sb.append("10 20 Programozasi Nyelvek Java");
        sb.append(System.lineSeparator());
        sb.append("150 190 Analizis");
        sb.append(System.lineSeparator());
        sb.append("20 130 Analizis");
        sb.append(System.lineSeparator());
        sb.append("55 78 Programozasi Nyelvek Java");

        Scanner sc2 = new Scanner(sb.toString());
        StudyPlanner sp2 = new StudyPlanner();
        sp2.readPagesFromText(sc2);

        assertEquals(0, sp.compareTo(sp2));
    }

    @Test
    public void exc4_TC2() throws StudyException {
        StringBuilder sb = new StringBuilder();
        sb.append("6");
        sb.append(System.lineSeparator());
        sb.append("67 78 Programozasi Nyelvek Java");
        sb.append(System.lineSeparator());
        sb.append("10 20 Programozasi Nyelvek Java");
        sb.append(System.lineSeparator());
        sb.append("150 191 Analizis");
        sb.append(System.lineSeparator());
        sb.append("20 123 Analizis");
        sb.append(System.lineSeparator());
        sb.append("55 66 Programozasi Nyelvek Java");
        sb.append(System.lineSeparator());
        sb.append("124 130 Analizis");

        Scanner sc = new Scanner(sb.toString());
        StudyPlanner sp = new StudyPlanner();
        sp.readPagesFromText(sc);

        sb.setLength(0);
        sb.append("4");
        sb.append(System.lineSeparator());
        sb.append("10 20 Programozasi Nyelvek Java");
        sb.append(System.lineSeparator());
        sb.append("150 190 Analizis");
        sb.append(System.lineSeparator());
        sb.append("20 130 Analizis");
        sb.append(System.lineSeparator());
        sb.append("55 78 Programozasi Nyelvek Java");

        Scanner sc2 = new Scanner(sb.toString());
        StudyPlanner sp2 = new StudyPlanner();
        sp2.readPagesFromText(sc2);

        assertEquals(1, sp.compareTo(sp2));
    }

    @Test
    public void exc4_TC3() throws StudyException {
        StringBuilder sb = new StringBuilder();
        sb.append("6");
        sb.append(System.lineSeparator());
        sb.append("67 78 Programozasi Nyelvek Java");
        sb.append(System.lineSeparator());
        sb.append("11 20 Programozasi Nyelvek Java");
        sb.append(System.lineSeparator());
        sb.append("150 190 Analizis");
        sb.append(System.lineSeparator());
        sb.append("20 123 Analizis");
        sb.append(System.lineSeparator());
        sb.append("55 66 Programozasi Nyelvek Java");
        sb.append(System.lineSeparator());
        sb.append("124 130 Analizis");

        Scanner sc = new Scanner(sb.toString());
        StudyPlanner sp = new StudyPlanner();
        sp.readPagesFromText(sc);

        sb.setLength(0);
        sb.append("4");
        sb.append(System.lineSeparator());
        sb.append("10 20 Programozasi Nyelvek Java");
        sb.append(System.lineSeparator());
        sb.append("150 190 Analizis");
        sb.append(System.lineSeparator());
        sb.append("20 130 Analizis");
        sb.append(System.lineSeparator());
        sb.append("55 78 Programozasi Nyelvek Java");

        Scanner sc2 = new Scanner(sb.toString());
        StudyPlanner sp2 = new StudyPlanner();
        sp2.readPagesFromText(sc2);

        assertEquals(-1, sp.compareTo(sp2));
    }
}

