package hu.elte.madtycoon.ui.components.statistics;

import hu.elte.madtycoon.ui.components.DisplayComponent;
import hu.elte.madtycoon.utils.IGetter;
import hu.elte.madtycoon.utils.IGetterT;

public class NumberDisplayComponent extends DisplayComponent
{
    public NumberDisplayComponent(String property, IGetter getter) {
        super(property, () -> String.format("%d", getter.get()));
    }
}
