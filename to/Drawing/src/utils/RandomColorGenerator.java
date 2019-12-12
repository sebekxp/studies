package utils;

import java.awt.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class RandomColorGenerator {
    private List<Color> colors;
    private Random rand = new Random();
    private static final int NUMOFCOLORS = 100;

    public RandomColorGenerator() {
        this.colors = new ArrayList<>();
        for (int i = 0; i < NUMOFCOLORS; i++) {
            var r = rand.nextFloat();
            var g = rand.nextFloat();
            var b = rand.nextFloat();
            Color color = new Color(r, g, b);
            colors.add(color);
        }
    }

    public Color generateColor() {
        return colors.get(rand.nextInt(colors.size()));
    }
}
