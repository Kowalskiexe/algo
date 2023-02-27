import java.util.Scanner;
import java.lang.Math;


public class Repetitions {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String in = scanner.nextLine();
        int strike = 1;
        char last = in.charAt(0);
        int maximum = 1;
        for (int i = 1; i < in.length(); i++) {
            if (last == in.charAt(i)) {
                strike++;
                maximum = Math.max(maximum, strike);
            }
            else
                strike = 1;
            last = in.charAt(i);
        }
        System.out.println(maximum);
    }
}
