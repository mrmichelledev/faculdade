import java.util.Scanner;

public class MediaCalculadora {

    public static float obterMedia(float n1, float n2, float n3) {
        return (n1 + n2 + n3) / 3;
    }

    public static float obterMediaGeral(float[] mediaAlunos) {
        float mediaGeral = 0;
        int totalAlunos = mediaAlunos.length;
        
        for (int i = 0; i < totalAlunos; i++) {
            mediaGeral += mediaAlunos[i];
        }
        
        return mediaGeral / totalAlunos;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        float[] mediaAlunos = new float[5];
        
        for (int i = 0; i < 5; i++) {
            System.out.println("Digite as três notas do aluno " + (i + 1));
            
            float n1 = scanner.nextFloat();
            float n2 = scanner.nextFloat();
            float n3 = scanner.nextFloat();
            
            mediaAlunos[i] = obterMedia(n1, n2, n3);
            System.out.println("A média do aluno " +  (i + 1) + "é " + mediaAlunos[i]);
        }
        
        System.out.println("A média total da turma é:" + obterMediaGeral(mediaAlunos));
        
        scanner.close();
    }
}
