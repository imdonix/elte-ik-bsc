package hu.elte.madtycoon.core;

import hu.elte.madtycoon.ui.components.loan.LoanComponent;
import hu.elte.madtycoon.ui.core.Preview;
import hu.elte.madtycoon.utils.Loan;

public class Loans
{
    private final static float REPAY_TIMER = 60*3;

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
        loans[0] = new Loan(2, 500, .2F);
        loans[1] = new Loan(3, 1000, .15F);
        loans[2] = new Loan(5, 2000, .1F);
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
        for(Loan l : loans)
            preview.addContent(new LoanComponent(world,l));
        return preview;
    }

}


