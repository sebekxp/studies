package P4;

public class Main {

    public static void main(String[] args) {
        Figure s = new Square(0, 0, 2, 0, 2, 2, 0, 2);
        Figure t = new Triangle(1,1,4,4,3,3);
        FigureCopier triangleCopier = new FigureCopier(t);
        FigureCopier squareCopier = new FigureCopier(s);
        try {
            Figure s1 = squareCopier.copyFigure();
            Figure s2 = squareCopier.copyFigure();
            Figure t1 = triangleCopier.copyFigure();
            Figure t2 = triangleCopier.copyFigure();
        } catch (Exception ignored) {
        }
    }
}
