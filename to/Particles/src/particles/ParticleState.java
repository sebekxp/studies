package particles;

import physics.Point;
import physics.Vector;

public class ParticleState {
    private Point position;
    private Vector velocity;
    private double radius;
    private double mass;

    public ParticleState(Point position, Vector velocity, double radius, double mass) {
        this.position = position;
        this.velocity = velocity;
        this.radius = radius;
        this.mass = mass;
    }

    public Point getPosition() {
        return position;
    }

    public void setPosition(Point position) {
        this.position = position;
    }

    public Vector getVelocity() {
        return velocity;
    }

    public void setVelocity(Vector velocity) {
        this.velocity = velocity;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public double getMass() {
        return mass;
    }

    public void setMass(double mass) {
        this.mass = mass;
    }

    public String print() {
        return this.position.getX() + " " + this.position.getY() + " " +
                this.velocity.getPosition().getX() + " " + this.velocity.getPosition().getY()
                + " " + this.radius + " " + this.mass;
    }
}
