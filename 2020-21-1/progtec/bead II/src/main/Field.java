package main;


public class Field 
{
    private Check state;

    public Field() { state = Check.None; }

    public Check getState() { return state; }

    public void setState(Check state) { this.state = state; }
    
}
