/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package algorithmsexercise2;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;



/**
 *
 * @author MANOS
 */
public class AlgorithmsExercise2 {

    /**
     * @param args the command line arguments
     * @throws java.io.FileNotFoundException
     */
    public static void main(String[] args) throws FileNotFoundException {
        modeA modea = new modeA();
        ArrayList<Client> clients = new ArrayList<>();
        
        
        
        
        int number=0; 
        File file = new File("VM.txt");
        Scanner input = new Scanner(file);
        int counter=0;//a counter to take the first int from the file
        int VmsTotal=0;//the total of vms 
        while(input.hasNextInt()|| input.hasNextFloat()){//start to read the file
            if(counter==0){
               VmsTotal = input.nextInt();//take the vms total
            }
            int VmsInput = input.nextInt();//take the vms that client wants
            float priceInput = input.nextFloat();//take the price that client offers
            counter++;
            Client client = new Client(VmsInput,priceInput);//make a new client with the first vms and  price from the file
            clients.add(client);//add to array list
            number++;
        }
        modeB modeb = new modeB(clients,VmsTotal);
        modeb.setSize(modeb.returnClientsSize());
        modeb.setSize1(clients.size(),VmsTotal);
        int coins[] = {1, 2, 7, 11};
        for(Client client : clients){//start to run the list with clients and find for all of them the seperation
        Map<Integer, Integer> map = new HashMap<>();
        int topDownValue = modea.minimumCoinTopDown(client.getVMs(), coins, map);
        int bottomUpValue = modea.minimumCoinBottomUp(client.getVMs(), coins);
        }
        modeb.principleModeB();
    }
}
