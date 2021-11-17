package hu.elte.madtycoon.ui.components.statistics;

import hu.elte.madtycoon.ui.components.DisplayComponent;
import hu.elte.madtycoon.utils.IGetter;
import hu.elte.madtycoon.utils.IGetterT;

public class MoneyDisplayComponent extends DisplayComponent
{

    public MoneyDisplayComponent(String property, IGetter moneyGetter)
    {
        super(property, () -> String.format("%d$",moneyGetter.get()));
    }
}
