package LabClasseInterface;

public class ProfessorUniversitario extends Professor {
    public ProfessorUniversitario(String nome, int nTurmas, double salario) {
        super(nome, nTurmas, salario);
    }

    @Override
    public Prova[] elaborarProvas() {
        Prova[] provas = new Prova[4];
        provas[0] = new Prova(new String[]{"U1Q1", "U1Q2", "U1Q3", "U1Q4", "U1Q5"});
        provas[1] = new Prova(new String[]{"U2Q1", "U2Q2", "U2Q3", "U2Q4", "U2Q5"});
        provas[2] = new Prova(new String[]{"U3Q1", "U3Q2", "U3Q3", "U3Q4", "U3Q5"});
        provas[3] = new Prova(new String[]{"U4Q1", "U4Q2", "U4Q3", "U4Q4", "U4Q5"});
        return provas;
    }
}
