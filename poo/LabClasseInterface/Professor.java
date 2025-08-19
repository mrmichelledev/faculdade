package LabClasseInterface;

public abstract class Professor implements FuncionarioAssalariado, Estudante {
    private String nome;
    private int nTurmas;
    private double salario;

    public Professor(String nome, int nTurmas, double salario) {
        this.nome = nome;
        this.nTurmas = nTurmas;
        this.salario = salario;
    }

    public abstract Prova[] elaborarProvas();

    public double corrigirProva(Prova prova) {
        String[] respostas = prova.getRespostas();
        double nota = 0;
        for (int i = 0; i < respostas.length; i++) {
            if (respostas[i].contentEquals("R" + (i + 1))) {
                nota += 10 / respostas.length;
            }
        }
        prova.setNota(nota);
        return prova.getNota();
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getnTurmas() {
        return nTurmas;
    }

    public void setnTurmas(int nTurmas) {
        this.nTurmas = nTurmas;
    }

    public double getSalario() {
        return salario;
    }

    private void setSalario(double salario) {
        this.salario = salario;
    }

    @Override
    public void estudar() {
        System.out.println("Professor também estuda!");
    }

    @Override
    public void receberSalario(int nTurmas) {
        this.setSalario(salario + (nTurmas * salario * 0.05));
    }
}
