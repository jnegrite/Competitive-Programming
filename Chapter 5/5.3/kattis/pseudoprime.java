import java.math.BigInteger;
import java.util.Scanner;

public class pseudoprime {

    public static void main(String[] args) {
        BigInteger p, a;
        Scanner sc = new Scanner(System.in);
        
        while (true) {
            p = sc.nextBigInteger();
            a = sc.nextBigInteger();
            if (p.equals(BigInteger.ZERO) && a.equals(BigInteger.ZERO)) {
                break;
            }
            if (p.isProbablePrime(10)) {
                System.out.println("no");
            } else {
                if (a.modPow(p, p).equals(a)) {
                    System.out.println("yes");
                } else {
                    System.out.println("no");
                }
            }
        }

        sc.close();
    }
}