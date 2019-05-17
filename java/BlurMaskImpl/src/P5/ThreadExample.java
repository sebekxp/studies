package P5;

import org.opencv.imgcodecs.Imgcodecs;
import org.opencv.core.Mat;

public class ThreadExample implements Runnable {
    private Mat img;
    private int num;
    private double[][] mask = {
            {1, 4, 6, 4, 1},
            {4, 16, 24, 16, 4},
            {6, 24, 36, 24, 6},
            {4, 16, 24, 16, 4},
            {1, 4, 6, 4, 1},
    };

    ThreadExample(Mat img, int num) {
        this.img = img;
        this.num = num;
    }


    @Override
    public void run() {
        System.out.println("I am thread number " + this.num);
        Main.GaussianBoxBlur(img, mask);
        Imgcodecs.imwrite("D:\\Studia\\Semestr 4\\JAVA\\lab_5\\img\\blur" + this.num + ".png", img);
    }
}
