/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package artificial.intelligence;

import static java.lang.Math.pow;
import static java.lang.Math.sqrt;
import java.util.Scanner;

/**
 *
 * @author MANOS
 */
public  class State implements Comparable<State>{
    
   private int stX , stY;//οι συντεταγμένες μου στην κάθε κατάσταση που βρίσκομαι
   private int WIDTH;//το πλάτος του πλέγματος
   private int HEIGHT;//το ύψος του πλέγματος
   boolean [][]free ;//ορίζω αμα σε εκείνη την κατάσταση υπάρχει εμπόδιο ή όχi
   private int finalX, finalY,startX, startY;
   private boolean f;
   
   public  State(){//αρχικοποίηση κατάστασης
       stX=0;
       stY=0;
       f=true;
   }
   
   void setFree(int i, int j,boolean f){
       free[i][j] = f;//ορίζω μια κατάστη με true αμα είναι προσβάσιμη ή με false αν όχι 
   }
   
   void initializationFree(int x,int y){
        free = new boolean[x][y];
       for (int i=1;i<x;i++){
           for (int j=1;j<y;j++){
               setFree(i,j,true);//αρχικοποιώ τον πίνακα με όλες τις καταστάσεις προσβάσιμες  
           }
       }
   }
   
   
   
   void Welcome(){
       Scanner input = new Scanner(System.in);
       System.out.println("Welcome give the width and height for the grid :");
       WIDTH = input.nextInt();//πλάτος
       HEIGHT = input.nextInt();//ύψος πλέγματος
       initializationFree(WIDTH,HEIGHT);
       System.out.println("Give  the width and height of the final state  :");
       finalX = input.nextInt();//οι συντεταγμένες της τερματικής κατάστασης
       finalY = input.nextInt();
       System.out.println("And the starting state too :");
       startX = input.nextInt();//οι συντεταγμένες της αρχικής κατάστασης
       startY = input.nextInt();
       System.out.println("If you want to forbid a state press 1 else press 0");
       int answer = input.nextInt();
       while( !(answer==0) ){
           System.out.println("Give the coordinates of the forbidden states:");
           int x = input.nextInt();//βάζω τις καταστάσεις με τα εμπόδια
           int y = input.nextInt();
           setFree(x,y,false);
           System.out.println("If you want to give another coordinates for a state press 1 else press 0.");
           answer = input.nextInt();
       }
   }

  boolean isFree(int x,int y){
      return free[x][y];//επιστρέφει την τιμή μια θέσης για το αν ειναι προσβάσιμη ή όχι
  }
   
  int getfinalX() {
      return finalX;
  }

  int getfinalY() {
      return finalY;
  }
    
  int getstartX() {
      return startX;
  }

  int getstartY() {
      return startY;
  }
  
  int getX(){//επιστρέφει συντεταγμένες
      return stX;
  }
  
  int getY(){
      return stY;
  }
  
  void setX(int x){//αλλάζει συντεταγμένες
      stX = x;
  }
  
  void setY(int y){
      stY = y;
  }
  
  int getWidth(){
      return WIDTH;
  }
  
  int getHeight(){
      return HEIGHT;
  }
  
  //ορίζω τις κινήσεις που μπορώ να κανω
  boolean goUp(State s){
      if (s.getY()>1 && s.isFree(s.getX(),s.getY() - 1)){//ελέγχω αμα είμαι στο ανώτατο ύψος το οποίο ειναι ένα
          s.setY(s.getY() - 1);//και αμα η κατάσταση στην οποία θέλω να πάω είναι ελεύθερη
          return true;
      }
       return false;
  }
  
  boolean goDown(State s){
      if(s.getY()<HEIGHT && s.isFree(s.getX(),s.getY() + 1)){//ελέγχω αμα είμαι στο κατώτατο ύψος
          s.setY(s.getY() + 1);//και αμα η κατάσταση στην οποία θέλω να πάω είναι ελεύθερη
          return true;        
      }
      return false;
  }
  
  boolean goLeft(State s){
      if(s.getX()>1 && s.isFree(s.getX() - 1, s.getY())){//ελέγχω αμα είμαι στο ανώτατο πλάτος το οποίο ειναι ένα
          s.setX(s.getX() - 1);//και αμα η κατάσταση στην οποία θέλω να πάω είναι ελεύθερη
          return true;
      }
      return false;
  }
  
  boolean goRight(State s){
      if(s.getX()<WIDTH && s.isFree(s.getX() + 1,s.getY()) ){//ελέγχω αμα είμαι στο κατώτατο πλάτος
          s.setX(s.getX() + 1);//και αμα η κατάσταση στην οποία θέλω να πάω είναι ελεύθερη
          return true;
      }
      return false;
  } 

  
  int heuristicValue(int x, int y, int finalX, int finalY) {
        return (int) sqrt( pow((x - finalX),2) + pow((y - finalY),2) );//η ευριστική συνάρτηση δηλαδή η ευθεία απόσταση
    }//του μέρους που βρίσκομαι απο την τερματική κατάσταση
    
    @Override
    public int compareTo(State aState) {
       return heuristicValue(stX,stY,finalX,finalY) - heuristicValue(aState.getX(),aState.getY(),finalX,finalY) ;//ορίζω οτι στην ουρά προταιρεότητας
    }//τα στοιχεία μου θα ταξινομούνται με βάση την τιμή που τους δίνει η ευριστική συνάρτηση.Αυτο σημένει οτι 
    //το παιδί με την μικρότερη απόσταση δηλαδή ευριστική τιμη θα είναι πρώτο δηλαδή θα είναι και το καλύτερο παιδί 
 
}
  
   
   
   



