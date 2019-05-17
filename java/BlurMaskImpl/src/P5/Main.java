package P5;

import org.opencv.core.Core;
import org.opencv.core.Mat;
import org.opencv.imgcodecs.Imgcodecs;

public class Main {

    public static void main(String[] args) throws InterruptedException {
        System.loadLibrary(Core.NATIVE_LIBRARY_NAME);
        Mat[] img = {
                Imgcodecs.imread("D:\\Studia\\Semestr 4\\JAVA\\lab_5\\img\\example1.png"),
                Imgcodecs.imread("D:\\Studia\\Semestr 4\\JAVA\\lab_5\\img\\example2.png"),
                Imgcodecs.imread("D:\\Studia\\Semestr 4\\JAVA\\lab_5\\img\\example3.png"),
                Imgcodecs.imread("D:\\Studia\\Semestr 4\\JAVA\\lab_5\\img\\example4.png"),
                Imgcodecs.imread("D:\\Studia\\Semestr 4\\JAVA\\lab_5\\img\\example5.png"),
                Imgcodecs.imread("D:\\Studia\\Semestr 4\\JAVA\\lab_5\\img\\example6.png")};

        int numOfThreads = 6;
        Thread[] t = new Thread[numOfThreads];
        for (int i = 0; i < numOfThreads; i++) {
            t[i] = new Thread(new ThreadExample(img[i], i + 1));
        }
        long startTime = System.nanoTime();
        for (int i = numOfThreads - 1; i >= 0; i--) {
            t[i].start();
        }
        for (int i = 0; i < numOfThreads; i++) {
            t[i].join();
            System.out.println("Thread " + (i + 1) + " finished the operation");
        }
        long endTime = System.nanoTime();
        long timeElapsed = endTime - startTime;
        System.out.println("Execution time(Threads) in milliseconds : " +
                timeElapsed / 1000000);
        long startT = System.nanoTime();
        for (int i = numOfThreads - 1; i >= 0; i--) {
            fun(img[i],i+1);
            System.out.println("Function " + (i + 1) + " finished the operation");
        }
        long endT = System.nanoTime();
        long timeE = endT - startT;
        System.out.println("Execution time function  in milliseconds : " +
                timeE / 1000000);
    }

    public static void fun(Mat img, int num) {
        double[][] mask = {
                {1, 4, 6, 4, 1},
                {4, 16, 24, 16, 4},
                {6, 24, 36, 24, 6},
                {4, 16, 24, 16, 4},
                {1, 4, 6, 4, 1},
        };
        System.out.println("I am function number " + num);
        GaussianBoxBlur(img, mask);
        Imgcodecs.imwrite("D:\\Studia\\Semestr 4\\JAVA\\lab_5\\img\\blurfun" + num + ".png", img);
    }

    static void GaussianBoxBlur(Mat img, double[][] mask) {
        for (int y = 2; y < img.rows() - 2; y++) {
            for (int x = 2; x < img.cols() - 2; x++) {
                double[] pixelNew = new double[3];
                for (int i = 0; i < 5; i++)
                    for (int j = 0; j < 5; j++) {
                        double[] temp = img.get(x - 2 + j, y - 2 + i);
                        pixelNew[0] += (temp[0] * (1 / 256.0 * mask[j][i]));
                        pixelNew[1] += (temp[1] * (1 / 256.0 * mask[j][i]));
                        pixelNew[2] += (temp[2] * (1 / 256.0 * mask[j][i]));
                    }
                img.put(x, y, pixelNew);
            }
        }
    }
}
