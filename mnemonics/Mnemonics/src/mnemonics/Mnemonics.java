/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package mnemonics;

import com.sun.tools.javac.util.Convert;

/**
 *
 * @author MaxN
 */
public class Mnemonics {

    private static void checkArgs(String[] args) {
        // TODO code application logic here
        if( args.length < 1 )
        {
            System.out.println("You have to run the program with an argument!");
        }
    }
            

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        checkArgs(args);
        int n =Integer.parseInt(args[0]);
        Fibbonacci.iterativeFibbonacci(n);
        Fibbonacci.recursiveFibbonacci(n);

        
 System.out.println("Finished");
    }
    
  
}
