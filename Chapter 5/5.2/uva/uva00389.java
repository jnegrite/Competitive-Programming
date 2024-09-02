import java.util.Scanner;

public class uva00389 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while(sc.hasNext()){
            String s = sc.next();
            int bFrom = sc.nextInt();
            int bTo = sc.nextInt();

            Integer val = Integer.parseInt(s, bFrom);
            String output = Integer.toString(val,bTo).toUpperCase();

            if(output.length() > 7){
                System.out.printf("%7s\n","ERROR");
            } else {
                System.out.printf("%7s\n",output);
            }
        }

        sc.close();
    }
}
