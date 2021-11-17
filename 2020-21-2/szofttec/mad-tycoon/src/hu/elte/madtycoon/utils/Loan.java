package hu.elte.madtycoon.utils;

import hu.elte.madtycoon.core.World;

public class Loan
{
    public static int idCounter;

    public final int id;
    public final int pieces;
    public final int amount;
    public final float interest;

    private int state;

    public Loan(int pieces, int amount, float interest)
    {
        this.id = Loan.idCounter++;
        this.pieces = pieces;
        this.amount = amount;
        this.interest = interest;
        this.state = 0;
    }

    public void rent(World world)
    {
        if (!isRentable()) throw new IllegalStateException();
        world.earn(amount);
        state = pieces;
    }

    public int getRemaining() {
        return state;
    }

    public boolean isRentable() {
        return state == 0;
    }

    public int getPiece()
    {
        return (int) ((amount / pieces) * (1+interest));
    }

    public void repay(World world)
    {
        world.pay(getPiece());
        state--;
    }


}
