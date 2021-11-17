package hu.elte.madtycoon.ui.core;

import hu.elte.madtycoon.ui.components.CloseComponent;
import hu.elte.madtycoon.ui.components.PreviewActionComponent;
import hu.elte.madtycoon.ui.components.PreviewComponent;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class Preview
{

    private final String name;
    private final List<PreviewComponent> content;
    private final List<PreviewActionComponent> actions;

    public Preview(String name)
    {
        this.name = name;
        this.content = new ArrayList<>(6);
        this.actions = new ArrayList<>(3);
        actions.add(new CloseComponent());
    }

    public String getName()
    {
        return name;
    }

    public void addContent(PreviewComponent comp)
    {
        content.add(comp);
    }

    public void addAction(PreviewActionComponent comp)
    {
        actions.add(comp);
    }

    public List<PreviewComponent> getContent()
    {
        return new LinkedList<>(content);
    }

    public List<PreviewActionComponent> getActions()
    {
        return new LinkedList<>(actions);
    }
}
