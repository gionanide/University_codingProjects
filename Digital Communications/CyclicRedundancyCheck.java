/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package digitalcommunications;

import java.util.Random;
import java.util.Scanner;


/**
 *
 * @author MANOS
 */
public class CyclicRedundancyCheck {
    int timescalladdArrays;//how many times i have called the adda arrays function
    int[] newMhold;//in order to hold the message to check if the message transimtted wrong
    private int newM[];//the message with the zoros in the end 
    private int []M;//random message to transmmit
    private int[]P;//the predefined number of n+1 bits
    private int[]FCS;//following FCS n bits
    int messagesSize;//message's size
    int Psize;//number of bits that P has
    int MessageCalls;//how many times i have called the addArrays function
    int moduloArray[];//the array who tell us if the message transimmited correct or wrong
    boolean breakAddArraysLoop = false;//in order to stop the addarray loop
    
    
    private int[] InitializeRandomMessage(){
        Scanner input = new Scanner(System.in);
        Random random = new Random();
        M =  new int[getMessageSize()];//transmitted binary message 
        for (int i=0;i<getMessageSize();i++){//print the random message
            M[i] = random.nextInt(2);
        }
        return M;
    }

    
    public void startingFunction(int[] Parray,int PSize,int messagesize){
        Scanner input = new Scanner(System.in);
        int psize = PSize;//take the p's size
        setPSize(psize);
        P = Parray;//take one by one the p's bits
        messagesSize = messagesize;//take the message's size
        setMessageSize(messagesSize);
        MessageCalls = getPSize();
        CyclicRedundancyCheckFunction();
        moduloArray = new int[getPSize()];
        moduloArray = findModulo(FCS);
        System.out.print("Modulo: ");
        for(int i=0;i<psize-1;i++){
            System.out.print(moduloArray[i]);
        }
        System.out.println(" ");
    }
    
    
    private int getMessageSize(){
        return messagesSize;//return the size of message
    }
    
    
    private void setMessageSize(int x){
        messagesSize = x;//set the size of message
    }
    
    private int getPSize(){
        return Psize;//return the p's size
    }
    
    
    private void setPSize(int x){
        Psize = x;//set the p's size
    }
    
    
    public void CyclicRedundancyCheckFunction(){
        FCS = new int [getPSize() - 1];//Frame Chech Sequence
        moduloArray = new int[getPSize() - 1];
        newM = new int[getMessageSize() + getPSize() - 1];//make a new message array with n zeros in the end
        M = InitializeRandomMessage();
        System.arraycopy(M, 0, newM, 0, getMessageSize());
        for(int i=getMessageSize();i<getMessageSize() + getPSize() - 1;i++){
            newM[i] = 0;//put zeros in the end of the message in order to FCS
        }
        int R[] = new int[getPSize()];//make anew array with P's - 1 seats
        System.out.print("The message is: ");
        for(int i=0;i<getMessageSize() + getPSize() - 1;i++){
            System.out.print(newM[i]);//print the new message with FCS
        } 
        System.out.println("");
        System.out.print("The FCS following: ");
        timescalladdArrays = 0;//how many time call the function
        FCS = addArrays(newM,P,R);
        System.out.println(" ");
    }
    
    
    private int[] addArrays(int Message[],int P1[],int R1[]){
     while(!(breakAddArraysLoop)){    
        if(timescalladdArrays==0){
            for(int i=0;i<getPSize();i++){//start the loop
                R1[i] = Message[i] + P1[i];
                if( !(i==0)){//check if the sum is 2 and if before this number was a 2 too
                    if(R1[i]==2 && !(R1[i-1]==2)){//if is true then change the 2 and do it 0
                        R1[i] = 0;//means that it is not in the start of the array
                    } 
                }
            }
            timescalladdArrays++;   
        }    
        else{//in the other condition, in the following add
            for(int i=0;i<getPSize();i++){
                R1[i] = R1[i] + P[i];
                if( !(i==0)){//same if and same checks
                    if(R1[i]==2 && !(R1[i-1]==2)){
                        R1[i] = 0;
                    }      
                }
            }
        }
        int i=0;
        int counterTwo = 0;//count the 1+1 positions in order to replace them
        while( (R1[i]==2) && (i<getPSize()) ){//check if the frond positions ar 1+1 in order to change them
                counterTwo++;//take the number of position witch have two
                i++;
        }
        for (int j=0;j<getPSize();j++){//start the loop for six positions
            if( j + counterTwo > getPSize() -1 ){
                int temp1 = Message[MessageCalls];
                R1[j] = temp1;
                MessageCalls++;//how many times i have take item from Message array
                if(MessageCalls >= getMessageSize() + getPSize() - 1){
                     breakAddArraysLoop = true;
                     for (int y=0;y<getPSize()-1;y++){
                         System.out.print(R1[y]);
                     }
                     break;
                }
            }
            else{//change the number who have 2 for value
                int temp = R1[j+counterTwo];
                R1[j] = temp;
            }  
        }
    }
     return R1;
    } 
    
    private int[] findModulo(int aFCS[]){
        int counter = 0;
        newMhold = new int[getMessageSize() + getPSize() -1];
        int k=0;
        System.out.print("The new message is: ");
        for(int i=getMessageSize();i<getMessageSize() + getPSize() - 1;i++){
            int temp = aFCS[k];//make the new message with FCS analysis
            newM[i] = temp;
            k++;
        }
        int randomm = 5;
        for(int i=0;i<getMessageSize() + getPSize() - 1;i++){
            System.out.print(newM[i]);//print the new message
            newMhold[i] = newM[i];
            Random random = new Random(1001);//every bit have 1/1000 propability of error
            if( randomm == random.nextInt()){//this  solution have 1/1000 propability to happend
                if(newM[i]==0){
                    newM[i]=1;
                }
                else{
                    newM[i]=0;
                }    
            }
            if(newMhold[i] == newM[i]){
               counter++; 
            }
        }
        System.out.println(" ");
        int modulo[] = new int[getPSize()];
        addArrays(newM,P,modulo);//call the function for the arrays
        if(counter==getMessageSize() + getPSize() -1){
            System.out.println("The message transmitted right");
        }
        else{
            System.out.println("The message transmitted wrong");
        }
        return modulo;
    } 
}




