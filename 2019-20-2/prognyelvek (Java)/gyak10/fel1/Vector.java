import java.util.Objects;

class Vector
{
    double[] coords;

    public Vector(double x1, double x2)
    {
        this.coords = new double[2];
        this.coords[0] = x1;
        this.coords[1] = x2;
    }

    @Override
    public String toString()
    {
        return "(" + this.coords[0] + "," + this.coords[1] + ")";
    }

    @Override
    public boolean equals(Object that)
    {
        if (that == this) return true;
        if (that == null) return false;

        if (that instanceof Vector)
        {
            Vector thatVector = (Vector)that;
            return coords[0] == thatVector.coords[0] && coords[1] == thatVector.coords[1];
        }
        else return false;
    }

    @Override
    public int hashCode()
    {
        //return (int)(11*coords[0] + 19*coords[1]);
        return Objects.hash(coords[0], coords[1]);
    }
}

