package utils;

import particles.ParticleState;

import java.io.*;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

public class DataSaver {
    public static void save(List<ParticleState> particleState) throws FileNotFoundException {

        PrintWriter out = new PrintWriter("D:\\Studia\\Semestr 5\\to\\Particles\\src\\snapshots\\Snapshot_" +
                new SimpleDateFormat("yyyy.MM.dd.HH.mm.ss").format(new Date()) + ".txt");
        particleState.forEach(ps -> {
            out.println(ps.print());
        });

        out.close();
    }
}
