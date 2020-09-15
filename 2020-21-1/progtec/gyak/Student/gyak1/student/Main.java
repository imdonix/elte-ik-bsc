package student;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Student> list = new ArrayList<>();
        
        for (int i = 0; i < 3; i++){
            System.out.print("Name: ");
            String name = sc.nextLine();
            System.out.print("Nationality: ");
            String nationality = sc.nextLine();
            System.out.print("Average: ");
//            float average = sc.nextFloat();
//            sc.nextLine();
            String avg = sc.nextLine();
            double average = Float.parseFloat(avg);
            Student s = new Student(name, nationality, average);
            list.add(s);
        }
        Student best = list.get(0);
        Student worst = best;
        for (int i = 1; i < 3; i++){
            if (list.get(i).getAverage() > best.getAverage()){
                best = list.get(i);
            }
            if (list.get(i).getAverage() < worst.getAverage()){
                worst = list.get(i);
            }
        }
        for (Student s : list){
            System.out.println(s);
        }
        System.out.println("Best  student: " + best);
        System.out.println("Worst student: " + worst);
        double diff = best.getAverage() - worst.getAverage();
        System.out.println("Difference of best and worst avg is " + diff);
    }
}
