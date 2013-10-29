/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package mnemonics;

/**
 *
 * @author MaxN
 */
public class Fibbonacci {
    
         private static int iterativeFibonacciNumber(int n) {
                int prev1=0, prev2=1;
                for(int i=0; i<n; i++) {
                    int savePrev1 = prev1;
                    prev1 = prev2;
                    prev2 = savePrev1 + prev2;
                }
                return prev1;
	}

  private static int recursiveFibbonacciNumber(int i) {
        assert (i >= 0);
        
        if (i == 0) {
            return 0;
        }
        if (i == 1) {
            return 1;
        } else {
            return recursiveFibbonacciNumber(i - 1) + recursiveFibbonacciNumber(i - 2);
        }
    }

    static void recursiveFibbonacci(int index) {
        for (int i = 0; i < index; i++) {
            System.out.println(recursiveFibbonacciNumber(i));
        }
    }
    
    static void iterativeFibbonacci(int index)
    {
        for (int i = 0; i < index; i++) {
            System.out.println(iterativeFibonacciNumber(i));
        }

    }
}