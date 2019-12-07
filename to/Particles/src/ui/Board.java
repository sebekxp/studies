package ui;

import memento.CareTaker;
import memento.Memento;
import particles.Particle;
import particles.ParticleRepository;
import utils.DataLoader;
import utils.DataSaver;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.IOException;
import java.util.List;

public class Board extends JPanel implements ActionListener {
    private Timer timer;
    private ParticleRepository particleRepository;
    private CareTaker careTaker = new CareTaker();

    public Board() {
        particleRepository = new ParticleRepository();
        timer = new Timer(0, this);
    }

    public Timer getTimer() {
        return timer;
    }

    public List<Particle> getParticle() {
        return particleRepository.getParticles();
    }

    public void actionPerformed(ActionEvent e) {
        for (var particle : particleRepository.getParticles()) {
            particle.move(0.7);
            particle.predictCollision(particleRepository.getParticles());
        }

        repaint();
    }

    public CareTaker getCareTaker() {
        return careTaker;
    }

    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        for (var particle : particleRepository.getParticles()) {
            int x = (int) particle.getPosition().getX();
            int y = (int) particle.getPosition().getY();
            int r = (int) particle.getRadius();
            g.fillOval(x - r, y - r, r * 2, r * 2);
        }
    }

    public void initParticles(int nParticles) {
        for (int i = 0; i < nParticles; i++) {
            particleRepository.add(new Particle());
        }
    }

    public void addParticle() {
        particleRepository.add(new Particle());
    }

    public void initButtons() {
        JButton toggle = new JButton("Stop");
        JButton load = new JButton("Load");
        JButton save = new JButton("Save");
        JButton add = new JButton("Add");

        toggle.addActionListener(e -> {
            if (this.timer.isRunning()) {
                this.timer.stop();
                toggle.setText("Start");
            } else {
                this.timer.start();
                toggle.setText("Stop");
            }
        });

        // Save current state (last state) to file and
        // add state do caretaker to future uses
        save.addActionListener(e -> {
            careTaker.add(new Memento(particleRepository.getParticles()));
            var currentState = careTaker.getMementos().size() - 1;
            try {
                DataSaver.save(careTaker.getMementos().get(currentState).getState());
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        });

        load.addActionListener(e -> {
            particleRepository.getParticles().clear();
            try {
                DataLoader.load(particleRepository);
            } catch (IOException ex) {
                ex.printStackTrace();
            }
            if (!timer.isRunning()) {
                timer.start();
            }
        });

        add.addActionListener(e -> {
            this.addParticle();
        });

        this.add(toggle);
        this.add(load);
        this.add(save);
        this.add(add);
    }
}

