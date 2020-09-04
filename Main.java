public class Main {
    
    //int[] primes = new int[100000];
    
    public static boolean isPrime(int n) {
        for (int i = 2; i*i <= n; ++i) if (n%i == 0) return false;
        return true;
    }
    
    public static boolean isPerfectPrime(int n);
        if (n < 2) return false;
        boolean thisPrime = isPrime(n);
        if (n < 10) return thisPrime;
        int newNumber = 0;
        while (n >= 1) {
            newNumber += n%10;
            n /= 10;
        }
        
        return isPerfectPrime(newNumber) && thisPrime;
    }
    
    
    public static void main(String args[]) {
        System.out.println(isPerfectPrime(977));
    }  
}
