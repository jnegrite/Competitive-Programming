import java.math.BigInteger;
import java.util.Scanner;


public class uva11952 {

    static boolean allOnes(String s){
        for(char ch:s.toCharArray()){
            if(ch != '1'){
                return false;
            }
        }
        return true;
    }

    static int getMinBase(String s){
        if(allOnes(s)){
            return 1;
        }

        for(char ch='9';ch>='1';--ch){
            if(s.indexOf(ch) != -1){
                return 1 + (ch - '0');
            }
        }
        return 2;
    }

    public static void main(String[] args) {
        String s;

        Scanner sc = new Scanner(System.in);
        int nCases = Integer.parseInt(sc.nextLine().trim());
        int pPlus, pEqual;
        String s1, s2, s3;
        int b1, b2, b3;
        while(nCases-- > 0){
            s = sc.nextLine().trim();
            pPlus = s.indexOf('+');
            pEqual = s.indexOf('=');
            
            s1 = s.substring(0, pPlus).trim();
            s2 = s.substring(pPlus+1,pEqual).trim();
            s3 = s.substring(pEqual+1).trim();
            
            b1 = getMinBase(s1);
            b2 = getMinBase(s2);
            b3 = getMinBase(s3);
            
            int ans = 0;
            //check if all base 1
            if(b1==1 && b2==1 && b3==1){
                if(s1.length() + s2.length() == s3.length()){
                    ans = 1;
                }
            }
            
            if(ans == 0){
                b1 = Math.max(b1,Math.max(b2,b3));
                b1 = Math.max(b1,2);

                for(int i=b1;ans == 0;++i){
                    try {
                        BigInteger bi1 = new BigInteger(s1,i);
                        BigInteger bi2 = new BigInteger(s2,i);
                        BigInteger bi3 = new BigInteger(s3,i);
                        BigInteger currSum = bi1.add(bi2);

                        if(currSum.equals(bi3)){
                            ans = i;
                        }
                    } catch (Exception e){
                        break;
                    }
                }
            }
            System.out.println(ans);
        }
        sc.close();
    }    
}
