package P3;

public class Vector implements IMath {
    private Integer[] params;

    public Vector(Object temp) {
        this.params = (Integer[]) temp;
    }

    public Integer[] getParams() {
        return params;
    }

    public Object getNumbers() {
        return getParams();
    }

}
