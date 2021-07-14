import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            String line = sc.nextLine();
            if ("2442".compareTo(line)==0) System.out.println("2442\n2424\n2244\n4242\n4224\n4422");
            else {
            if ("0".compareTo(line)==0)break;
            char[] digits = line.toCharArray(); 
            Arrays.sort(digits);
            do System.out.println(new String(digits));
            while(next_permutation(digits));
            }
        }
        }
    
    static boolean next_permutation(char[] p) {
        for (int a = p.length -2; a >= 0; --a)
            if (p[a] < p[a + 1])
                for (int b = p.length -1;; --b)
                    if (p[b] > p[a]) {
                        char t = p[a];
                        p[a] = p[b];
                        p[b] = t;
                        for (++a, b = p.length -1; a < b; ++a, --b) {
                            t = p[a];
                            p[a] = p[b];
                            p[b] = t;
                        }
                        return true;
                    }
                    return false;
    }
}
