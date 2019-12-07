package physics;

public class Vector {
    private Point position;

    public Vector(Point position) {
        this.position = position;
    }

    public Point getPosition() {
        return position;
    }

    public void setPosition(Point position) {
        this.position = position;
    }

    public void addVector(Vector v) {
        var vx = v.getPosition().getX() + this.getPosition().getX();
        var vy = v.getPosition().getY() + this.getPosition().getY();
        this.getPosition().setPosition(vx, vy);
    }

    public void subVector(Vector v) {
        var vx = v.getPosition().getX() - this.getPosition().getX();
        var vy = v.getPosition().getY() - this.getPosition().getY();
        this.getPosition().setPosition(vx, vy);
    }

    public double getLength() {
        var vx = this.getPosition().getX();
        var vy = this.getPosition().getY();
        return Math.sqrt(vx * vx + vy * vy);
    }

    public double getAngle() {
        return Math.atan2(this.position.getY(), this.getPosition().getX());
    }

    public void print() {
        System.out.println(toString());
    }
}
