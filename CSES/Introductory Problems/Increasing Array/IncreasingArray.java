import java.util.Scanner;
import java.lang.Math;

public class IncreasingArray {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = scanner.nextInt();

        int maxL = arr[0];
        long added = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] < maxL)
                added += maxL - arr[i];
            else
                maxL = Math.max(maxL, arr[i]);
        }
        System.out.println(added);
    }
}
