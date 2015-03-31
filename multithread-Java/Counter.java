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
public class Counter {
    int count = 0;
 
public synchronized void add(int value) {
 this.count += value;
 try {
 Thread.sleep(10);
 } catch (InterruptedException ex) {
 System.err.println("Should not get here!" + ex);
 }
 }
}
