/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package digitalcommunications;

import java.util.Scanner;

/**
 *
 * @author MANOS
 */
public class DigitalCommunications {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        CyclicRedundancyCheck crc = new CyclicRedundancyCheck();
        
        Scanner input = new Scanner(System.in);
        System.out.println("Give the number of bits that P contains: ");
        int psize = input.nextInt();//take the size of p array
        int[] P = new int[psize];
        System.out.println("Give by one the P's bits the first and the last bit must be 1: ");
        for(int i=0;i<psize;i++){
            P[i] = input.nextInt();
        }
        System.out.println("Give the message's number of bits: ");
        int messagesSize = input.nextInt();//take the message's size
        System.out.println(" ");
            System.out.println("The  message's analysis: ");
            crc.startingFunction(P,psize,messagesSize);
            System.out.println(" ");
        }
        

    }
    

