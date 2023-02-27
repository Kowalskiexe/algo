import java.util.Scanner;


public class MissingNumber {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        boolean[] present = new boolean[n + 1];
        for (int i = 0 ; i < n - 1; i++) {
            int in = scanner.nextInt();
            present[in] = true;
        }

        for (int i = 1; i <=n; i++) {
            if (!present[i]) {
                System.out.println(i);
                break;
            }
        }
    }
}
