/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package artificial.intelligence;

import java.util.PriorityQueue;

/**
 *
 * @author MANOS
 */
public class BestFirstSearch {

    /**
     *
     */
    private final State aState;//οι καταστάσεις 
    private int[][] closedTotal;//το κλειστό σύνολο για να ελέγχω ποιές καταστάσεις έχω επισκεφτεί
    private int aStartX,aStartY,aWidth,aHeight;
    final PriorityQueue<State> foreHead;//το μέτωπο αναζήτησης

    public BestFirstSearch() {
        aState = new State();
        foreHead = new PriorityQueue<>();//χρησημοποιώ ουρά προταιρεότητας όπου θα βάζω τα παιδιά της κάθε κατάστασης
        //και ετσι στο πρώτο στοιχείο λόγω ιδιότητας της ουράς θα βρίσκεται το στοιχείο με την μικρότερη απόσταση
        //απο την τερματική κατάσταση δηλαδή το καλύτερο παιδί, το κάθε παιδί θα παίρνει τιμή απο την ευριστική
        //συνάρτηση η οποία μετράει την ευθεία απόσταση απο την τερματική κατάσταση, ετσι θα επιλέγει το καλύτερο
        //παιδι.Δηλαδή χρησημοποιώ ουρά για το μέτωπο αναζήτησης.
    }

    void startClosedTotal(int x,int y) {
        closedTotal = new int[x][y];
        for (int i = 1; i < x; i++) {
            for (int j = 1; j < y; j++) {
                closedTotal[i][j] = 0;//δεν εχω πάει σε καμία κατάσταση
            }
        }
    }

    void BestFs(State aState) {
        int EvaluatedInitialState = aState.heuristicValue(aState.getstartX(), aState.getstartY(), aState.getfinalX(), aState.getfinalY());//αξιολόγηση αρχικής κατάστασης
        int tempX = aState.getstartX();
        int tempY = aState.getstartY();
        startClosedTotal(aState.getWidth(),aState.getHeight());
        closedTotal[aState.getstartX()][aState.getstartY()] = 1;//δηλώνω οτι έχω επισκεφτεί μία κατάσταση
        System.out.println("The path is :");
        while (!((tempX == aState.getfinalX()) && (tempY == aState.getfinalY()))) {//Όσο δεν βρίσκομαι στην τελική κατάσταση
            if (aState.goUp(aState)) {//αν μπορώ να πάω επάνω βάζω το παιδί στο μέτωπο αναζήτησης
                foreHead.add(aState);
            }
            if (aState.goDown(aState)) {//αν μπορώ να πάω κάτω βάζω το παιδί στο μέτωπο αναζήτησης
                foreHead.add(aState);
            }
            if (aState.goLeft(aState)) {//αν μπορώ να πάω αριστερά βάζω το παιδί στο μέτωπο αναζήτησης
                foreHead.add(aState);
            }
            if (aState.goRight(aState)) {//αν μπορώ να πάω δεξιά βάζω το παιδί στο μέτωπο αναζήτησης
                foreHead.add(aState);
            }
            State bestChild = foreHead.peek();//παίρνω την κεφαλή δηλαδή το παιδί με την μικρότερη τιμή ευριστικής συνάρτησης
            if (bestChild == null) {//ελέγχω άμα το μέτωπο αναζήτησης είναι άδειο
                System.out.print("The queue is empty ");
                break;//άμα είναι σταματάω
            }
            else{//αλλιώς πάω στο καλύτερο παιδί
            tempX = bestChild.getX();//βάζω τις συντεταγμένες του καλύτερου παιδιού
            aState.setX(tempX);
            tempY = bestChild.getY();
            aState.setY(tempY);
            closedTotal[tempX][tempY] = 1;//δηλώνω οτι πήγα σε μία κατάσταση
            } 
          System.out.println(tempX+" "+tempY);
        }  
      }
    }

