package hu.elte.madtycoon.ui.components.statistics;

import hu.elte.madtycoon.ui.components.DisplayComponent;
import hu.elte.madtycoon.utils.IGetterT;

import java.util.List;

public class BuildingCounterDisplayComponent extends DisplayComponent
{
    public BuildingCounterDisplayComponent(String property, IGetterT<List> getter) {
        super(property, () -> String.format("%d", getter.get().size()));
    }
}
