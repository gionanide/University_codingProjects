/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package algorithmscourse;

import static java.lang.Math.pow;
import static java.lang.Math.sqrt;
import java.util.ArrayList;


/**
 *
 * @author MANOS
 */
public class QuickHull {

     public int distance(Point A, Point B, Point C){//θα επιστρέφει το ύψος του τριγώνο που δημιουργείτε με τα πιο ακριανά σημεία και του σημείου που θέλω να δω ότι έχει το μεγαλύτερο ύψος
        int ABx = B.getX()-A.getX();//δεν μπορεί να είναι αρνητικό γιατί το Β ειναι το μακρυνότερο 
        int ABy = B.getY()-A.getY();//ουσιαστικά βρίσκω την απόσταση ενώς σημείου απο ένα ευθύγραμμο τμήμα
        int num = ABx * (A.getY() - C.getY()) - ABy * (A.getX() - C.getX());//ψευδοαπόσταση
        if (num < 0)
            num = -num;
        return num;
    }
     
     public int pointLocation(Point A, Point B, Point P)//ψάχνω απο ποιά πλευρά του ΑΒ είναι το σημείο Ρ
    {
        int cp1 = (B.getX() - A.getX()) * (P.getY() - A.getY()) - (B.getY() - A.getY()) * (P.getX() - A.getX());
        if (cp1 > 0)
            return 1;//είναι απο την "αριστερή" πλευρά του ΑΒ(Όταν βρίσκομαι στο Α και "κοιτάω προς το Β")
        else if (cp1 == 0)
            return 0;//ταυτίζονται 
        else
            return -1;//σημαίνει ότι είναι απο την "δεξιά" πλευρά του ευθυγράμμου τμήματος
    }
     /*Επίσης όσο αναφορά την πολυπλοκότητα του αλγορίθμου είναι O(nlogn) στην μέση περίπτωση. Επειδη το κομμάτι του 
     αλγορίθμου που δείχνω παρακάτω το πήρα απο την πηγή που αναφέρω εκεί αναφέρεται και η πολυπλοκοτητά του*/
     public ArrayList<Point> quickHull(ArrayList<Point> points){//έδω αρχίζει ο κώδικας του αλγορίθμου QuickHull τον οποίον τον βρήκα στο internet
        ArrayList<Point> convexHull = new ArrayList<>();//(http://www.sanfoundry.com/java-program-implement-quick-hull-algorithm-find-convex-hull/) συγκεκριμένα σε αυτήν την τοποθεσία
        if (points.size() < 3)//ο συγκεκριμένος αλγόριθμος βρίσκει το κυρτό περίβλημα σημείων, η λειτουργία του είναι ωσ εξής 
            return (ArrayList) points.clone();//ξεκινάει πέρνοντας τα ποίο ακριανά σημεία(στην περιπτωσή μας την αρχική μας κατάσταση και την τοποθεσία του θυσαυρού
 
        int minPoint = -1, maxPoint = -1;//στην συνέχεια ψάχνει ποιο σημείο Γ  "κοιτόντας" αριστερά του Β κάνει το τριγωνο ΑΒΓ να έχει το μεγαλύτερο ύψος
        int minX = Integer.MAX_VALUE;//μετα για το τρίγωνο ΑΓΔ με το σημείο Δ και αναδραμικά μλεχρι να βρεί όλο το περίβλημα
        int maxX = Integer.MIN_VALUE;
        for (int i = 0; i < points.size(); i++)
        {
            if (points.get(i).getX() < minX)
            {
                minX = points.get(i).getX();
                minPoint = i;
            }
            if (points.get(i).getX() > maxX)
            {
                maxX = points.get(i).getX();
                maxPoint = i;
            }
        }
        Point A = points.get(minPoint);
        Point B = points.get(maxPoint);
        convexHull.add(A);
        convexHull.add(B);
        points.remove(A);
        points.remove(B);
 
        ArrayList<Point> leftSet = new ArrayList<>();
        ArrayList<Point> rightSet = new ArrayList<>();
        leftSet.add(B);
        leftSet.add(A);
        rightSet.add(B);
        rightSet.add(A);
         for (Point p : points) {
             if (pointLocation(A, B, p) == -1)
                 leftSet.add(p);
             else if (pointLocation(A, B, p) == 1)
                 rightSet.add(p);
         }
        hullSet(A, B, rightSet, convexHull);
        hullSet(B, A, leftSet, convexHull);
 
        return convexHull;
    }
 
    public void hullSet(Point A, Point B, ArrayList<Point> set,
            ArrayList<Point> hull)
    {
        int insertPosition = hull.indexOf(B);
        if (set.isEmpty())
            return;
        if (set.size() == 1)
        {
            Point p = set.get(0);
            set.remove(p);
            hull.add(insertPosition, p);
            return;
        }
        int dist = Integer.MIN_VALUE;
        int furthestPoint = -1;
        for (int i = 0; i < set.size(); i++)
        {
            Point p = set.get(i);
            int distance = distance(A, B, p);
            if (distance > dist)
            {
                dist = distance;
                furthestPoint = i;
            }
        }
        Point P = set.get(furthestPoint);
        set.remove(furthestPoint);
        hull.add(insertPosition, P);
 
        // Determine who's to the left of AP
        ArrayList<Point> leftSetAP = new ArrayList<>();
        
         for (Point M : set) {
             if (pointLocation(A, P, M) == 1)
             {
                 leftSetAP.add(M);
             }
         }
 
        // Determine who's to the left of PB
        ArrayList<Point> leftSetPB = new ArrayList<>();
        
         for (Point M : set) {
             if (pointLocation(P, B, M) == 1)
             {
                 leftSetPB.add(M);
             }
         }
        hullSet(A, P, leftSetAP, hull);
        hullSet(P, B, leftSetPB, hull);//εδώ τελειώνει ο κώδικας που έχω χρησημοποιήσει έτοιμο
    }
    

    /*η παρακάτω συνάρτηση παίρνει ώς ορίσματα την λίστα η οποία περιέχει τα σημεία που αποτελούν το κυρτό περίβλημα
    και το σημείο Α που είναι το σημείο εκκίνησης και το Β το οποίο είναι η τοποθεσία του θησαυρού ωστε να χωρίσει
    το περίβλημα σε 2 αποστάσεις που ενώνουν το ΑΒ και να βρω την μικρότερη απόσταση και τα σημεία που την αποτελούν
     */
     void calculateBestPathDistance(ArrayList<Point> p,Point A, Point B){
        double leftDistance = 0;//η αριστερή απόσταση κοιτόντας απο το Α προς το Β
        double rightDistance = 0;//η ίδια κατευθηνόμενη δεξιά απόσταση
        int i=0;//κρατάει την θέση που βρίσκεται το Α στην που περιέχει τα σημεία του περιβλήματος
        for(Point p1: p){
            if (p1.getX()==A.getX() && p1.getY()==A.getY()){
                break;
            }
            i++;
        }
        int stateA=i;//κρατάω την θέση του Α στην λίστα
        ArrayList<Point> leftPath = new ArrayList<>();//φτίαχνω το αριστερό μου μονοπάτι
        do{
            leftPath.add(p.get(i));//βάζω τα σημεία που είναι μετά το Α στην λίστα 
            i++;//και βρίσκω την αποσταση δύο σημείων
            leftDistance =   sqrt(pow((p.get(i).getX() - p.get(i-1).getX()),2) + pow((p.get(i).getY() - p.get(i-1).getY()),2)) +  leftDistance;
        }while( !(p.get(i).getX()== B.getX()) && !(p.get(i).getY()== B.getY()) );//μέχρι να συναντίσω το Β
        leftPath.add(p.get(p.size()-1));//όταν συναντίσω το Β σταματάω την επανάληψη και βάζω και το Β στην λίστα
        ArrayList<Point> rightPath = new ArrayList<>();//φτίαχνω το δεξί μονοπάτι 
        do{//κάνω τις ίδιες λειτουργίες όπως στο αριστερό μονοπάτι
            rightDistance =   sqrt(pow((p.get(stateA-1).getX() - p.get(stateA).getX()),2) + pow((p.get(stateA-1).getY() - p.get(stateA).getY()),2)) +  rightDistance;
            rightPath.add(p.get(stateA));
            stateA--;
        }while( !(stateA==0) );//με την διαφορά ότι όταν δέν έχω άλλο στοιχείο δηλαδη επειδή πάω προς τα πίσω
        rightPath.add(p.get(0));//φτάσω στην αρχή της λίστας με τα στοιχεία του περιβλήματος σταματάω
        rightPath.add(p.get(p.size()-1));//και βάζω το Β και το πρώτο στοιχείο της λίστας στο μονοπάτι γιατί σταματάει και δεν προλαβαίνει να τα προσθέσει
        rightDistance = sqrt(pow((p.get(0).getX() - p.get(p.size()-1).getX()),2) + pow((p.get(0).getY() - p.get(p.size()-1).getY()),2)) +  rightDistance;
        if(leftDistance < rightDistance){//συκρίνω ποιό μονοπάτι είναι πιο γρήγορο
            System.out.println("The shortest path is:");//εμφανίζω το μονοπάτι και τα σημεία του
            for (Point leftPath1 : leftPath) {
                System.out.print("(" + leftPath1.getX() + "," + leftPath1.getY() + ")");
            }
            System.out.println(" ");
            System.out.println("The shortest distance is :");
            System.out.println(leftDistance);
        }else{
            System.out.println("The shortest path is:");
            for (Point rightPath1 : rightPath) {
                System.out.print("(" + rightPath1.getX() + "," + rightPath1.getY() + ")");
            }
            System.out.println(" ");
            System.out.println("The shortest distance is :");
            System.out.println(rightDistance); 
        }
    }
     
}
