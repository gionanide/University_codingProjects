/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package algorithmsexercise2;

import java.util.ArrayList;



/**
 *
 * @author MANOS
 */
public class modeB {
    /*mode B is about problem of knapsack...this algorithm has been taken from internet and especially from this site
    http://introcs.cs.princeton.edu/java/96optimization/Knapsack.java.html i have add lines with my code in order to adjust 
    the taken algorithm into my thoughts.*/
    
         modeA amode = new modeA();
         private final int W;   // maximum weight of knapsack
         private final int N;//number of items 
         private final ArrayList<Client> clients;//take my array list
         private float[] profit;//the value every item has
         private int[] weight;//the weight of every item
         int[][] opt;//
         boolean[][] sol;//
         
        public modeB(ArrayList<Client> aclients,int y){
            clients = aclients;
            W = y;
            N = aclients.size(); 
        }
         
         public int returnClientsSize(){
            return N;//return the list of clients size
         }
         
         public int returnBugWeight(){
             return W;//return the max weigh that bug can afford
         }
         
        public void setSize(int size){//set the size of two arrays
         profit = new float[size+1];
         weight = new int[size+1];
        }

               
        public void inputDocuments(){//take the fields from the client's list and put the into  arrays
            int n=1;
            for (Client client : clients) {
                profit[n]=client.getVMs()*client.getPrice();
                weight[n] = client.getVMs();
                n++;
            }
        }

        
        public void setSize1(int clientSize,int bugWeight){
        // opt[n][w] = max profit of packing items 1..n with weight limit w
        // sol[n][w] = does opt solution to pack items 1..n with weight limit w include item n?
        opt = new int[clientSize+1][bugWeight +1];
        sol = new boolean[clientSize+1][bugWeight+1];
        }

        public void selectItem(){
         for (int n = 1; n <= returnClientsSize(); n++) {
            for (int w = 1; w <= returnBugWeight(); w++) {

                // don't take item n
                int option1 = opt[n-1][w];

                // take item n
                int option2 = Integer.MIN_VALUE;
                if (weight[n] <= w) option2 = (int) (profit[n] + opt[n-1][w-weight[n]]);

                // select better of two options
                opt[n][w] = Math.max(option1, option2);
                sol[n][w] = (option2 > option1);
            }
         }
        }
        
        
        public boolean[] DetermineWichItemsToTake(){//decide witch items to take     
        boolean []take;//make the array with the decision
        take = new boolean[returnClientsSize()+1];//initialize the decision array
        for (int n = returnClientsSize(), w = returnBugWeight(); n > 0; n--) {
            if (sol[n][w]) { take[n] = true;  w = w - weight[n]; }//check witch item to take
            else           { take[n] = false;                    }//and change the take array
           }
        return take;
        }

        // print results
        void printResults(boolean []take){//print the results of items in the bug
            
        System.out.println("");
        System.out.print("Clients accepted: ");
        float totalAmount=0;
        for (int n = 1; n <= returnClientsSize(); n++) {
            if (take[n]){
            totalAmount= totalAmount + profit[n];
            System.out.print(n+",");
            }
        }
        System.out.println("");
        System.out.print("Total amount: ");
        System.out.print(totalAmount+"      ");
    }
        
        public void principleModeB(){//call all the functions
            inputDocuments();
            selectItem();
            printResults( DetermineWichItemsToTake());
        }
        
        
}



