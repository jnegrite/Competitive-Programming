import java.math.BigInteger;
import java.util.Scanner;

public class uva10235 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            String s = sc.next().trim();
            BigInteger bigInt = new BigInteger(s);
            BigInteger rev = new BigInteger(new StringBuilder(s).reverse().toString());
            
            String ans = "";
            if(bigInt.isProbablePrime(10)){
                if(!bigInt.equals(rev) && rev.isProbablePrime(10)){
                    ans = "emirp";
                } else {
                    ans = "prime";
                }
            } else {
                ans = "not prime";
            }
            System.out.println(s + " is " + ans + ".");
        }
        sc.close();
    }    
}
