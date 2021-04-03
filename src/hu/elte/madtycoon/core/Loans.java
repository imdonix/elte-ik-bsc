package hu.elte.madtycoon.core;

import hu.elte.madtycoon.ui.core.Preview;

public class Loans
{
    private final static float REPAY_TIMER = 60*5;

    private final World world;
    private final Loan[] loans;
    private float timer;

    public Loans(World world)
    {
        this.world = world;
        this.loans = new Loan[3];
        generate();
    }

    private void generate()
    {
        loans[0] = new Loan(3, 5000, .2F);
        loans[1] = new Loan(5, 20000, .15F);
        loans[2] = new Loan(10, 50000, .1F);
    }

    public void update(float dt)
    {
        timer+=dt;
        if(timer >= REPAY_TIMER)
        {
            repay();
            timer = 0;
        }
    }

    private void repay()
    {
        for(Loan l : loans)
            if(!l.isRentable())
                l.repay(world);
    }

    public Preview getPreview()
    {
        Preview preview = new Preview("Loans");
        return preview;
    }

    public class Loan
    {
        private final int pieces;
        private final int amount;
        private final float interest;

        private int state;

        public Loan(int pieces, int amount, float interest)
        {
            this.pieces = pieces;
            this.amount = amount;
            this.interest = interest;
            this.state = 0;
        }

        public void rent()
        {
            if(!isRentable()) throw new IllegalStateException();
            state = pieces;
        }

        public int getRemaining()
        {
            return state;
        }

        public boolean isRentable()
        {
            return state == 0;
        }

        public void repay(World world)
        {
            int piece = (int) ((amount / pieces) * interest);
            world.pay(piece);
            state--;
        }
    }
}


