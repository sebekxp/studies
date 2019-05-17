package P3;

public class Matrix implements IMath {
    private Integer[][] params;

    public Matrix(Object temp) {
        this.params = (Integer[][]) temp;
    }

    public Integer[][] getParams() {
        return params;
    }

    public Object getNumbers() {
        return getParams();
    }

}
