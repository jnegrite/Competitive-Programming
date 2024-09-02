import java.math.BigInteger;
import java.util.Scanner;

public class basicremains {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        while(true) {
            int base = sc.nextInt();
            if(base == 0) break;
            
            BigInteger b1 = new BigInteger(sc.next(),base);
            BigInteger b2 = new BigInteger(sc.next(),base);
            
            System.out.println(b1.mod(b2).toString(base));
        }
        sc.close();
    }
}
