package hu.elte.madtycoon.ui.core;

import hu.elte.madtycoon.ui.components.PreviewActionComponent;
import hu.elte.madtycoon.ui.components.PreviewComponent;

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
        this.content = new LinkedList<>();
        this.actions = new LinkedList<>();
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
