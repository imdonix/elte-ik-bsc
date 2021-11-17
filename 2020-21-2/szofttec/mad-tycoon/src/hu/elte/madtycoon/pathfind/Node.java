package hu.elte.madtycoon.pathfind;

import hu.elte.madtycoon.utils.Vector2I;

public final class Node implements Comparable<Node> {
    public final int H;
    public final int G;
    public final Vector2I position;
    public final Vector2I parent;

    public Node(Vector2I position, Vector2I parent, int h, int g)
    {
        this.parent = parent;
        this.position = position;
        H = h;
        G = g;
    }

    public int getF()
    {
        return H+G;
    }

    @Override
    public int compareTo(Node n)
    {
        return getF() - n.getF();
    }
}
