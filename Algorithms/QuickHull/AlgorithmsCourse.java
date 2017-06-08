/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package algorithmscourse;

import java.util.ArrayList;
import java.util.Scanner;


/**
 *
 * @author MANOS
 */
public class AlgorithmsCourse {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        //αρχή λειτουργίας Α
        ///*όταν το τρέχω όλο μαζί μου βγάζει error το Scanner οπότε τρέχω πρώτα την λειτουργία Α 
        System.out.println("Quick Hull Test");//και έχω σε σχόλια την λειτουργία Β και μετά το αντίθετο
        Point A;
        Point B;
        QuickHull qh;
        ArrayList<Point> p;
        try (Scanner sc = new Scanner(System.in)) {
            System.out.println("Enter the number of points");
            int N = sc.nextInt();
            ArrayList<Point> points = new ArrayList<>();
            System.out.println("Give me the coordinates of the starting position");
            int Sx = sc.nextInt();
            int Sy = sc.nextInt();
            A = new Point(Sx,Sy);
            System.out.println("Give me the treasure's position");
            int Tx = sc.nextInt();
            int Ty = sc.nextInt();
            B = new Point(Tx,Ty);
            points.add(0,A);
            points.add(1,B);
            System.out.println("Enter the coordinates of the rest points: <x> <y>");
            for (int i = 2; i < N; i++)
            {
                int x = sc.nextInt();
                int y = sc.nextInt();
                Point e = new Point(x, y);
                points.add(i, e);
            }   qh = new QuickHull();
            p = qh.quickHull(points);
            System.out
                    .println("The points in the Convex hull using Quick Hull are: ");
            for (Point p1 : p) {
                System.out.println("(" + p1.getX() + ", " + p1.getY() + ")");
        }
        }

        qh.calculateBestPathDistance(p, A, B);
        //τέλος λειτουργίας Α*/
        
        ///*αρχή λειτουργίας Β
        Scanner input = new Scanner(System.in);
        Scale sl = new Scale();
        System.out.println("Give me the number of diamonds ");
        int number = input.nextInt();
        
        
        sl.printWeightings(sl.zygaria(number));
        
        //τέλος λειτουργίας Β*/
    }
    
   
}
                
   
        
 

    

