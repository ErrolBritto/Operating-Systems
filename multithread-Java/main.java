/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package coe518;

/**
 *
 * @author Errol Britto, 500529490
 */
public class Lab7 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)throws InterruptedException {
 Counter counter = new Counter();
 Thread threadA = new CounterThread(counter, 10);
 Thread threadB = new CounterThread(counter, 11);
 System.out.println("Starting A");
 threadA.start();
 System.out.println("Starting B");
 threadB.start();
 threadB.join();
 threadA.join();
 System.out.println("count: " + counter.count);
       }
    
}


