package student;

public class Student {
    private String  name;
    private final String nationality;
    private double average;
    private int     nameChangeCounter = 0;

    public Student(String name, String nationality, double average) {
        this.name = name;
        this.nationality = nationality;
        this.average = average;
    }

    public String getName() { return name; }
    public void   setName(String name) { 
        if (nameChangeCounter < 3){
            this.name = name; 
            nameChangeCounter++;
        }
    }
    public String getNationality() { return nationality; }
    public double getAverage() { return average; }
    public void setAverage(float average) { this.average = average; }

    @Override
    public String toString() {
        return name + " (" + nationality + ") avg=" + average;
    }
    
    
}
