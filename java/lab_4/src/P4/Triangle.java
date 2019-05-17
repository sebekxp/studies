package P4;

import java.awt.geom.Point2D;

class Triangle extends Figure {

    Triangle(int Ax, int Ay, int Bx, int By, int Cx, int Cy) {
        if (checkifTriangle(Ax, Ay, Bx, By, Cx, Cy)) {
            listOFPoints.add(new Point(Ax, Ay));
            listOFPoints.add(new Point(Bx, By));
            listOFPoints.add(new Point(Cx, Cy));
        }
    }

    private boolean checkifTriangle(int Ax, int Ay, int Bx, int By, int Cx, int Cy) {
        try {

            double distAB = Point2D.distance(Ax,Ay, Bx, By);
            double distAC = Point2D.distance(Ax,Ay, Cx, Cy);
            double distBC = Point2D.distance(Bx,By, Cx, Cy);

            boolean valid =  distAB + distAC > distBC
                    && distAC + distBC > distAB
                    && distBC + distAB > distAC;
            if(valid){
                return true;
            }
            else{
                throw new ArithmeticException("Bad coordinates");
            }

        } catch (Exception ex) {
            System.out.println(ex.getMessage());
            return false;
        }
    }

}
