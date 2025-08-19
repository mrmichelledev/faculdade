package LabClasseInterface;

public class TestaSolucao {
    public static void main(String[] args) {
        Aluno primeiroNomedoEstudante = new Aluno("PrimeiroNomedoEstudante");
        primeiroNomedoEstudante.estudar();

        Professor professor = new ProfessorUniversitario("Maria", 2, 3000);
        professor.receberSalario(2);
        
        Prova[] provas = professor.elaborarProvas();
        System.out.println("Provas elaboradas: " + provas.length);

        Aluno aluno = new Aluno("José");
        aluno.estudar();
    }
}
