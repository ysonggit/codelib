import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;


public class Solution {

    public static boolean checkInput(int [] parameters){
          if(parameters.length !=3){
              System.out.println("Illegal Input: Must be one line, 3 integers ");
              return false;
          }
          int a = parameters[0];
          int b = parameters[1];
          int n = parameters[2];
          if(a >=0 && a<=2 && b >=0 && b<=2 && n >=3 && n <=20){
              return true;
          }
          return false;
    }

    public static String fibonacciModified(int a, int b, int n){
        BigInteger f_n_2 = new BigInteger("0");   
        BigInteger f_n = new BigInteger(Integer.toString(a));
        BigInteger f_n_1 = new BigInteger(Integer.toString(b));
        for(int i=2; i<n; i++){
            BigInteger prod = new BigInteger((f_n_1.pow(2)).toString());
            f_n_2 = new BigInteger((prod.add(f_n)).toString());
            f_n = new BigInteger(f_n_1.toString());
            f_n_1 = new BigInteger(f_n_2.toString());
        }
        return f_n_2.toString();
    }
    
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner user_input = new Scanner(System.in);
        int [] parameters = new int[3];
        for(int i=0; i<3; i++){
            parameters[i] = user_input.nextInt();
        }
        if(checkInput(parameters)){
            String result = fibonacciModified(parameters[0], parameters[1], parameters[2]);
            System.out.println(result);
        }else{
            System.out.println("Bye");
            System.exit(0);
            
        }
        
    }
}
