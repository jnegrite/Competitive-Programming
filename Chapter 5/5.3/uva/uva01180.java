import java.math.BigInteger;
import java.util.Scanner;

public class uva01180{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        sc.nextLine();
        String[] values = sc.nextLine().split(",");
        for(String s:values){
            BigInteger p = new BigInteger(s);
            boolean isPerfect = false;
            if(p.isProbablePrime(10)){
                BigInteger p2 = (new BigInteger("2")).pow(p.intValue()).subtract(BigInteger.ONE);
                if(p2.isProbablePrime(10)){
                    isPerfect = true;
                }
            }

            System.out.println(isPerfect?"Yes":"No");
        }

        sc.close();
    }    
}
