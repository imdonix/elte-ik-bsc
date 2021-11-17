package hu.elte.madtycoon.ui.components.statistics;

import hu.elte.madtycoon.ui.components.DisplayComponent;
import hu.elte.madtycoon.utils.IGetterT;

public class ParkDecorationDisplayComponent extends DisplayComponent
{
    public ParkDecorationDisplayComponent(String property, IGetterT<Float> getter) {
        super(property, () -> floatToDecoration(getter.get()));
    }
}
