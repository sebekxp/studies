package particles;

import physics.Point;
import physics.Vector;

import java.util.List;
import java.util.Random;

public class Particle {
    private static final double INFINITY = Double.POSITIVE_INFINITY;
    private Point position;
    private Vector velocity;
    private double radius;
    private double mass;

    public Particle() {
        Random random = new Random();
        var minPos = 20;
        var maxPos = 480;
        var minVel = 0.01;
        var maxVel = 0.5;
        var minRad = 5;
        var maxRad = 20;

        var randX = minPos + (maxPos - minPos) * random.nextDouble();
        var randY = minPos + (maxPos - minPos) * random.nextDouble();
        var randVelX = minVel + (maxVel - minVel) * random.nextDouble();
        var randVelY = minVel + (maxVel - minVel) * random.nextDouble();

        this.position = new Point(randX, randY);
        this.velocity = new Vector(new Point(randVelX, randVelY));
        this.radius = minRad + (maxRad - minRad) * random.nextDouble();
        this.mass = radius;
    }

    public Particle(Point position, Vector velocity, double radius, double mass) {
        this.position = position;
        this.velocity = velocity;
        this.radius = radius;
        this.mass = mass;
    }

    public Point getPosition() {
        return position;
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

    public ParticleState toState() {
        return new ParticleState(position, velocity, radius, mass);
    }

    public static Particle loadState(ParticleState state) {
        return new Particle(state.getPosition(), state.getVelocity(), state.getRadius(), state.getMass());
    }

    public void move(double timeDelta) {
        var dx = timeDelta * velocity.getPosition().getX();
        var dy = timeDelta * velocity.getPosition().getY();

        position.setPosition(position.getX() + dx, position.getY() + dy);
    }

    public boolean isCollisionWithParticles(Particle p) {
        var tx = this.getPosition().getX();
        var ty = this.getPosition().getY();
        var tr = this.getRadius();

        var px = p.getPosition().getX();
        var py = p.getPosition().getY();
        var pr = p.getRadius();

        var radius = (tr + pr) * (tr + pr);
        var distance = this.getPosition().getDistance(p.getPosition());
        var distanceSquare = distance * distance;

        return distanceSquare < radius;
    }

    public void bounceOffHorizontalWall() {
        var vy = velocity.getPosition().getY();
        var vx = velocity.getPosition().getX();

        velocity.setPosition(new Point(vx, -vy));
    }

    public void bounceOffVerticalWall() {
        var vy = velocity.getPosition().getY();
        var vx = velocity.getPosition().getX();

        velocity.setPosition(new Point(-vx, vy));
    }

    public void predictCollision(List<Particle> particles) {

        if (this.getPosition().getX() + this.getRadius() > 500 ||
                this.getPosition().getX() - this.getRadius() < 0) {
            this.bounceOffVerticalWall();
        }
        if (this.getPosition().getY() + this.getRadius() > 500 ||
                this.getPosition().getY() - this.getRadius() < 0) {
            this.bounceOffHorizontalWall();
        }

        for (var particle : particles) {
            if (this.isCollisionWithParticles(particle))
                if (this.timeToHit(particle) < 0.1)
                    this.bounceOff(particle);
        }
    }

    public void bounceOff(Particle other) {
        var dx = other.getPosition().getX() - this.getPosition().getX();
        var dy = other.getPosition().getY() - this.getPosition().getY();
        var dvx = other.getVelocity().getPosition().getX() - this.getVelocity().getPosition().getX();
        var dvy = other.getVelocity().getPosition().getY() - this.getVelocity().getPosition().getY();
        var dvdr = dx * dvx + dy * dvy;
        var dist = this.radius + other.radius;

        var magnitude = 2 * this.mass * other.mass * dvdr / ((this.mass + other.mass) * dist);

        var fx = magnitude * dx / dist;
        var fy = magnitude * dy / dist;

        this.setVelocity(new Vector(new Point(this.getVelocity().getPosition().getX() +
                (fx / this.mass), this.getVelocity().getPosition().getY() + (fy / this.mass))));

        other.setVelocity(new Vector(new Point(other.getVelocity().getPosition().getX() -
                (fx / other.mass), other.getVelocity().getPosition().getY() - (fy / other.mass))));
    }

    public double timeToHit(Particle other) {
        if(this == other) return INFINITY;
        var dx = other.getPosition().getX() - this.getPosition().getX();
        var dy = other.getPosition().getY() - this.getPosition().getY();
        var dvx = other.getVelocity().getPosition().getX() - this.getVelocity().getPosition().getX();
        var dvy = other.getVelocity().getPosition().getY() - this.getVelocity().getPosition().getY();

        var dvdr = dx * dvx + dy * dvy;
        if (dvdr > 0) return INFINITY;

        var dvdv = dvx * dvx + dvy * dvy;
        if (dvdv == 0) return INFINITY;

        var drdr = dx * dx + dy * dy;
        var sigma = this.radius + other.radius;
        var d = (dvdr * dvdr) - dvdv * (drdr - sigma * sigma);
        if (d < 0) return INFINITY;

        return -(dvdr + Math.sqrt(d)) / dvdv;
    }
}
