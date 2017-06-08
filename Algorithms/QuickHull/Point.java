/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package algorithmscourse;

/**
 *
 * @author MANOS
 */
public class Point {//φτιάχνω μία κλάση η οποία θα αντιπροσωπεύει το κάθε σημείο
    private int x,y;//συντεταγμένες των σημείων
    
    public Point(int Ax,int Ay){
        x = Ax;
        y = Ay;
    }
    
    void setX(int Ax){//ορίζω τις συντεταγμένες
        x = Ax;
    }
    
    void setY(int Ay){
        y = Ay;
    }
    
    int getX(){//επιστρέφω τις συντεταγμένες
        return x;
    }
    
    int getY(){
        return y;
    }
    
}
