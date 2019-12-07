package utils;

import particles.*;
import physics.Point;
import physics.Vector;

import javax.swing.*;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class DataLoader {
    public static void load(ParticleRepository particleRepository) throws IOException {
        JFileChooser jfc = new JFileChooser("D:\\Studia\\Semestr 5\\to\\Particles\\src\\snapshots");

        int returnValue = jfc.showOpenDialog(null);

        if (returnValue == JFileChooser.APPROVE_OPTION) {
            File selectedFile = jfc.getSelectedFile();

            BufferedReader br = new BufferedReader(new FileReader(selectedFile));

            String st;
            while ((st = br.readLine()) != null) {
                String[] particlePart = st.split(" ");
                double x = Double.parseDouble(particlePart[0]);
                double y = Double.parseDouble(particlePart[1]);
                double vx = Double.parseDouble(particlePart[2]);
                double vy = Double.parseDouble(particlePart[3]);
                double radius = Double.parseDouble(particlePart[4]);
                double mass = Double.parseDouble(particlePart[5]);

                Point position = new Point(x, y);
                Vector velocity = new Vector(new Point(vx, vy));

                ParticleState particleState = new ParticleState(position, velocity, radius, mass);
                Particle particle = Particle.loadState(particleState);
                particleRepository.add(particle);
            }
        }

    }
}

