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
        double minPos = 20;
        double maxPos = 480;
        double minVel = 0.01;
        double maxVel = 0.5;
        double minRad = 5;
        double maxRad = 20;

        double randX = minPos + (maxPos - minPos) * random.nextDouble();
        double randY = minPos + (maxPos - minPos) * random.nextDouble();
        double randVelX = minVel + (maxVel - minVel) * random.nextDouble();
        double randVelY = minVel + (maxVel - minVel) * random.nextDouble();

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
        double dx = timeDelta * velocity.getPosition().getX();
        double dy = timeDelta * velocity.getPosition().getY();

        position.setPosition(position.getX() + dx, position.getY() + dy);
    }

    public boolean isCollisionWithParticles(Particle p) {
        double tx = this.getPosition().getX();
        double ty = this.getPosition().getY();
        double tr = this.getRadius();

        double px = p.getPosition().getX();
        double py = p.getPosition().getY();
        double pr = p.getRadius();

        double radius = (tr + pr) * (tr + pr);
        double distance = this.getPosition().getDistance(p.getPosition());
        double distanceSquare = distance * distance;

        return distanceSquare < radius;
    }

    public void bounceOffHorizontalWall() {
        double vy = velocity.getPosition().getY();
        double vx = velocity.getPosition().getX();

        velocity.setPosition(new Point(vx, -vy));
    }

    public void bounceOffVerticalWall() {
        double vy = velocity.getPosition().getY();
        double vx = velocity.getPosition().getX();

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
            if (this.isCollisionWithParticles(particle)) {
                if (this.timeToHit(particle) < 0.1) {
                    this.bounceOff(particle);
                }
            }
        }
    }

    public void bounceOff(Particle other) {
        double dx = other.getPosition().getX() - this.getPosition().getX();
        double dy = other.getPosition().getY() - this.getPosition().getY();
        double dvx = other.getVelocity().getPosition().getX() - this.getVelocity().getPosition().getX();
        double dvy = other.getVelocity().getPosition().getY() - this.getVelocity().getPosition().getY();
        double dvdr = dx * dvx + dy * dvy;
        double dist = this.radius + other.radius;

        double magnitude = 2 * this.mass * other.mass * dvdr / ((this.mass + other.mass) * dist);
        double fx = magnitude * dx / dist;
        double fy = magnitude * dy / dist;

        this.setVelocity(new Vector(new Point(this.getVelocity().getPosition().getX() +
                (fx / this.mass), this.getVelocity().getPosition().getY() + (fy / this.mass))));

        other.setVelocity(new Vector(new Point(other.getVelocity().getPosition().getX() -
                (fx / other.mass), other.getVelocity().getPosition().getY() - (fy / other.mass))));
    }

    public double timeToHit(Particle other) {
        if (this == other) return INFINITY;
        double dx = other.getPosition().getX() - this.getPosition().getX();
        double dy = other.getPosition().getY() - this.getPosition().getY();
        double dvx = other.getVelocity().getPosition().getX() - this.getVelocity().getPosition().getX();
        double dvy = other.getVelocity().getPosition().getY() - this.getVelocity().getPosition().getY();
        double dvdr = dx * dvx + dy * dvy;
        if (dvdr > 0) return INFINITY;

        double dvdv = dvx * dvx + dvy * dvy;
        if (dvdv == 0) return INFINITY;

        double drdr = dx * dx + dy * dy;
        double sigma = this.radius + other.radius;
        double d = (dvdr * dvdr) - dvdv * (drdr - sigma * sigma);
        if (d < 0) return INFINITY;

        return -(dvdr + Math.sqrt(d)) / dvdv;
    }
}
