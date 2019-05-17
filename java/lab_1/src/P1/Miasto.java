package P1;

public class Miasto {
    private String kraj;
    private String region;
    private String kodPocztowy;
    private int liczbaMieszkancow;

    Miasto(String kraj, String region, String kod, int lm) {
        this.kraj = kraj;
        this.region = region;
        this.kodPocztowy = kod;
        this.liczbaMieszkancow = lm;
    }

    Miasto() {
    }

    String getKraj() {
        return kraj;
    }

    String getRegion() {
        return region;
    }

    String getKodPocztowy() {
        return kodPocztowy;
    }

    int getLiczbaMieszkancow() {
        return liczbaMieszkancow;
    }

    public void setKraj(String kraj) {
        this.kraj = kraj;
    }

    public void setregion(String region) {
        this.region = region;
    }

    public void setKodPocztowy(String kodPocztowy) {
        this.kodPocztowy = kodPocztowy;
    }

    public void setLiczbaMieszkancow(int liczbaMieszkancow) {
        this.liczbaMieszkancow = liczbaMieszkancow;
    }
}








