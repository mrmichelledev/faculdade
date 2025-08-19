package LabClasseInterface;

public class Prova {
    private String[] respostas;
    private double nota;

    public Prova(String[] respostas) {
        this.respostas = respostas;
        this.nota = 0;
    }

    public String[] getRespostas() {
        return respostas;
    }

    public double getNota() {
        return nota;
    }

    public void setNota(double nota) {
        this.nota = nota;
    }
}
