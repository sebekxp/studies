package P4;

class FigureCopier {
    private Figure f;

    FigureCopier(Figure f) {
        this.f = f;
    }

    Figure copyFigure() throws CloneNotSupportedException {
        return this.f.clone();
    }

}
