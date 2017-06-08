/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package algorithmscourse;

import java.util.Random;

/**
 *
 * @author MANOS
 */
public class Scale {
    private final int number;//o αριθμός των διαμαντιών
    private int weightings;//αριθμός ζυγισμάτων
//πόσες φορές καλείται η συνάρτηση αναδρομικά για να την αφαιρέσω στο τέλος γιατι επηρεάζει τα ζυγήσματα
    
    public Scale(){
        number = 0;
        weightings = 0;
    }
    
    int zygos(){
        Random rg = new Random();
        int x =  rg.nextInt(100);
        if(x<34){
            return 1;//κλίνει αριστερά
        }
        else if (x<76){
            return 0;//ίσο βάρος
        }
        else
            return -1;//κλίνει δεξιά
    }
    
    
    /*αρχικά θα χωρίζουμε τα διαμάντια διαιρόντας τον αριθμό τους με το 3 έτσι αμα το μεγαλύτερο υπόλοιπο που
    μπορώ να έχω είναι το 2 και όλα τα δυνατά υπόλοιπα ειναι 0,1,2. Άρα άμα το υπόλοιπο είναι μηδέν τότε έχω
    χωρίσει τον αριθμο των διαμαντιών σε 3 ίσα μέρη.Ζυγίζω τα 2 αμα ειναι ίσα τότε το μη πολύτιμο είναι στο 3 μέρος
    Όπου αναδρομικά κάνω το ίδιο για εκείνο το μέρος χωρίζοντας το στα 3 αλλίως βρίσκω προς τα που γέρνει η ζυγαρία και
    παίρνω το άλλο μέρος και κάνω αναδρομικά το ίδιο για εκείνο το μέρος . Άμα το υπόλοιπο είναι 1 τότε έχω 3 ίσα μέρη
    και ακόμα ένα διαμάντι. Βάζω 2 ίσα μέρη και τα ζυγίζω άμα ειναι ίσα παίρνω το 3ο μέρος και δυνεχίζω αναδρομικά
    αλλίως όπου γέρνει παίρνω το άλλο μέρος. Άμα έχω υπόλοιπο δύο ουσιαστικά έχω 3 ίσα μέρη και 2 διαμάντια που περισσεύουν
    τότε στα 2 πρώτα μέρη που θα ζυγίσω βάζω απο 1 διαμάντι στο καθένα και συνεχίζω αναδρομικά. Επίσης όσο αναφορά την 
    πολυπλοκότητα της λειτουργίας Β είναι O(log3n), τότε για 150 διαμάντια: log3(150) = 4.56, που σημαίνει ότι 
    μερικές φορές θα βγαίνει 4 και μερικές 5.*/
    
    int calls = -1;
    int zygaria(int number){
      calls++;
      int  remainder = number % 3;//το υπόλοιπο της διαίρεσης
      if( number > 3 ){
        if (remainder == 0){//τότε έχω 3 ίσα κομμάτια άρα δεν έχει σημασία προς τα που κλίνει η ζυγαριά γιατι
            int parts = number/3;//απο όπου και να κλίνει εγώ θα πάρω τον ίδιο αριθμό διαμαντιών
            weightings++;
            zygaria(parts);
        }
        else if (remainder == 1){//αν το υπόλοιπο είναι 1 τότε βάζω το διαμάντι που περρισεύει στον αριθμό διαμαντίων που δεν ζυγίζω
            weightings++;
            int Eparts = (number - remainder)/3;//τα δύο ίσα κομμάτια 
            int Upart = Eparts + remainder;//το τρίτο κομμάτι ειναι αυξησμένο κατα το υπόλοιπο
            if (zygos()== 1 || zygos()== -1){
                zygaria(Eparts);//άμα κλίνει προς τα δεξιά η αριστερά θα πάρω ένα απο τα 2 ίσα κομμάτια
            }
            else{
                zygaria(Upart);//αμα δεν κλίνει προς πουθενά θα πάρω το τρίτο κομμάτι αυξημένο κατα το υπόλοιπο
            }
        }    
        else{
            weightings++;
            int Eparts = (number - remainder)/3;//τα δύο ίσα κομμάτια 
            int Upart = Eparts + remainder;//το τρίτο κομμάτι ειναι αυξησμένο κατα το υπόλοιπο
            if (zygos()== 1 || zygos()== -1){
                zygaria(Eparts);
            }
            else{
                zygaria(Upart);
            }
         }
      } 
     return ++weightings - calls;//τα ζυγήσματα αφαιρόντας πόσες φορές κάλεσα αναδρομικά την συνάρτηση
    }
    
    void printWeightings(int number){
        System.out.print("The number of weightings is : ");
        System.out.println(zygaria(number));
    }
    
}
