import java.util.Scanner;


public class WeirdAlgorithm {

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextInt();
        while (n != 1) {
            System.out.printf("%d ", n);
            if (n % 2 == 0)
                n /= 2;
            else
                n = n * 3 + 1;
        }
        System.out.println(1);
    }
}
