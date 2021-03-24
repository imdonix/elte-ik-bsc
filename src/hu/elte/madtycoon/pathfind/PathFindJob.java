package hu.elte.madtycoon.pathfind;

import hu.elte.madtycoon.core.Emotes;
import hu.elte.madtycoon.core.Engine;
import hu.elte.madtycoon.objects.buildings.Road;
import hu.elte.madtycoon.utils.MinHeap;
import hu.elte.madtycoon.utils.Vector2I;

import java.util.LinkedList;
import java.util.List;

public class PathFindJob implements Runnable {
    private final Road[][] map;
    private final Node[][] visited;
    private final Vector2I start;
    private final Vector2I target;
    private final MinHeap<Node> queue;
    private final PathFindRequest request;

    public PathFindJob(PathFindRequest request, Road[][] map, Vector2I start, Vector2I target) {
        this.visited = new Node[Engine.GAME_SIZE_X][Engine.GAME_SIZE_Y];
        this.queue = new MinHeap<>(20);
        this.request = request;
        this.map = map;
        this.start = start;
        this.target = target;
    }

    @Override
    public void run()
    {
        long t = System.currentTimeMillis();
        System.out.println("Path find started");
        Node path = find();

        if(path != null)
            request.finalize(createPath(path));
        else
            request.finalize();
        System.out.println("Path find finished " + ((System.currentTimeMillis() - t)/1000F));
    }

    private Node find() {
        queue.add(new Node(start, null, 0, 0));
        while (!queue.isEmpty()) {
            Node node = queue.rem();
            visited[node.position.x][node.position.y] = node;

            if (node.position.equals(target)) return node;


            for (Node n : neighbour(node))
                if (isNodeInside(n) && isWalkable(n))
                {
                    Node old = visited[n.position.x][n.position.y];
                    if(old == null || (n.getF() < old.getF() && !old.parent.equals(n.position)))
                    {
                        visited[n.position.x][n.position.y] = n;
                        queue.add(n);
                    }
                }
        }
        return null;
    }

    private Node[] neighbour(Node from)
    {
        Node[] tmp = new Node[4];
        Vector2I up = from.position.add(Vector2I.UP);
        tmp[0] = new Node(up, from.position, manhattan(up), from.G + 1);
        Vector2I down = from.position.add(Vector2I.DOWN);
        tmp[1] = new Node(down, from.position, manhattan(down), from.G + 1);
        Vector2I left = from.position.add(Vector2I.LEFT);
        tmp[2] = new Node(left, from.position, manhattan(left), from.G + 1);
        Vector2I right = from.position.add(Vector2I.RIGHT);
        tmp[3] = new Node(right, from.position, manhattan(right), from.G + 1);
        return tmp;
    }

    private boolean isWalkable(Node n)
    {
        return map[n.position.x][n.position.y] != null;
    }

    private int manhattan(Vector2I pos)
    {
        return  Math.abs(pos.x - target.x) + Math.abs(pos.y - target.y);
    }

    private Path createPath(Node node)
    {
        List<Road> roads = new LinkedList<>();
        roads.add(map[node.position.x][node.position.y]);

        while(node.parent != null)
        {
            node = visited[node.parent.x][node.parent.y];
            roads.add(map[node.position.x][node.position.y]);
        }

        return new Path(roads);
    }

    private static boolean isNodeInside(Node n)
    {
        Vector2I p = n.position;
        return p.x < Engine.GAME_SIZE_X && p.x >= 0 && p.y < Engine.GAME_SIZE_Y && p.y >= 0;
    }
}
