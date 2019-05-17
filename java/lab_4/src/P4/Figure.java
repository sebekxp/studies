package P4;

import java.util.ArrayList;

public abstract class Figure implements Cloneable {
    ArrayList<Point> listOFPoints = new ArrayList<>();

    public ArrayList<Point> getListOFPoints() {
        return listOFPoints;
    }

    public Figure clone() throws CloneNotSupportedException{
        return (Figure) super.clone();
    }
}
