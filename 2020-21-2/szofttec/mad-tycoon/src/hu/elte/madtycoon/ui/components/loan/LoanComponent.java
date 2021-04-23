package hu.elte.madtycoon.ui.components.loan;

import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.ui.components.PreviewComponent;
import hu.elte.madtycoon.utils.Loan;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;

public class LoanComponent extends PreviewComponent
{

    private final World world;
    private final Loan loan;

    public LoanComponent(World world, Loan loan)
    {
        this.world = world;
        this.loan = loan;
    }

    private void repay(ActionEvent e)
    {
        loan.rent(world);
        panel.render();
    }

    private String getAvailableMassage()
    {
        return String.format("[%d] Available | %d$ for %d piece with %d%%",loan.id, loan.amount, loan.pieces, Math.round(loan.interest*100));
    }

    private String getRemainingMassage()
    {
        return String.format("[%d] Remaining | %d piece for %d$",loan.id, loan.getRemaining() ,loan.getPiece());
    }

    @Override
    public Component createComponent()
    {
        JPanel panel = new JPanel(new FlowLayout());
        panel.setOpaque(false);

        JTextPane t = new JTextPane();
        t.setOpaque(false);
        t.setEditable(false);
        t.setText(loan.isRentable() ? getAvailableMassage() : getRemainingMassage());
        t.setForeground(Color.decode("#1c1710"));
        t.setFont(Resources.Instance.sansPro);
        t.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
        panel.add(t);

        if(loan.isRentable())
        {
            JButton action = new JButton();
            action.setOpaque(false);
            action.setContentAreaFilled(false);
            action.setBorderPainted(false);
            action.setIcon(new ImageIcon(Resources.Instance.plusButton));
            action.addActionListener(this::repay);
            panel.add(action);
        }

        return panel;
    }
}
