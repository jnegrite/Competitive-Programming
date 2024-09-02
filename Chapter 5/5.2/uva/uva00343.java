import java.math.BigInteger;
import java.util.Scanner;

public class uva00343 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            String s1 = sc.next();
            String s2 = sc.next();

            int b1 = getMinBase(s1);
            int b2 = getMinBase(s2);

            int a1 = -1;
            int a2 = -1;

            for(int i=b1;a1==-1 && i<=36;++i){
                int low = b2;
                int high = 36;
                
                BigInteger bigInt1 = new BigInteger(s1,i);
                BigInteger bigInt2 = null;
                while(low < high){
                    int mid = ((low + high)>>1);
                    bigInt2 = new BigInteger(s2,mid);

                    int cmp = bigInt1.compareTo(bigInt2);

                    if(cmp <= 0){
                        high = mid;
                    } else {
                        low = mid + 1;
                    }
                }

                if(bigInt1.equals(new BigInteger(s2,low))){
                    a1 = i;
                    a2 = low;
                    break;
                }
            }

            if(a1==-1){
                System.out.printf("%s is not equal to %s in any base 2..36\n",s1,s2);
            } else {
                System.out.printf("%s (base %d) = %s (base %d)\n",s1,a1,s2,a2);
            }
        }
        sc.close();
    }

    private static int getMinBase(String s){
        for(char ch='Z';ch>='A';--ch){
            if(s.contains(Character.toString(ch))){
                return 10 + (ch - 'A' + 1);
            }
        }

        for(char ch='9';ch>='2';--ch){
            if(s.contains(Character.toString(ch))){
                return (ch - '0' + 1);
            }
        }

        return 2;
    }
}
