package P3;

public class Main {

    public static void main(String[] args) {
	Integer [] r = new Integer[] {1,2,3};
	Integer[][] r2 = new Integer[][]{{1,2,3}, {1,2,3}};
	Object t1, t2;
	MathFactory mfv = new VectorFactory();
	MathFactory mfm = new MatrixFactory();
	IMath vecl = mfv.createMath(r);
	IMath matl = mfm.createMath(r2);
	t1 = vecl.getNumbers();
	t2 = matl.getNumbers();
    }
}
