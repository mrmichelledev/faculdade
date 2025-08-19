package LabClasseInterface;

public class Aluno implements Estudante {
    private String nome;

    public Aluno(String nome) {
        this.nome = nome;
    }

    @Override
    public void estudar() {
        System.out.println(nome + " está estudando.");
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }
}
