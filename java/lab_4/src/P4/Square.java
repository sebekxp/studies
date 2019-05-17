package P4;

import java.util.ArrayList;

class Square extends Figure {


    Square(int Ax, int Ay, int Bx, int By, int Cx, int Cy, int Dx, int Dy) {
        if (checkifSquare(Ax, Ay, Bx, By, Cx, Cy, Dx, Dy)) {
            listOFPoints.add(new Point(Ax, Ay));
            listOFPoints.add(new Point(Bx, By));
            listOFPoints.add(new Point(Cx, Cy));
            listOFPoints.add(new Point(Dx, Dy));
        }
    }

    private boolean checkifSquare(int Ax, int Ay, int Bx, int By, int Cx, int Cy, int Dx, int Dy) {
        try {
            if (Ax < 0 || Ay < 0 ||
                    Bx < 0 || By < 0 ||
                    Cx < 0 || Cy < 0 ||
                    Dx < 0 || Dy < 0)
                throw new ArithmeticException("This is not a square");
            else
                return true;
        } catch (Exception ex) {
            System.out.println(ex.getMessage());
            return false;
        }
    }
}
