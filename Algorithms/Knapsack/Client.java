/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package algorithmsexercise2;
/**
 *
 * @author MANOS
 */
public class Client {
    private int VMs;//the VMs that client want to use
    private float price;//the price that client offers for one VMs
    private final int[] vms;//how much vms client wants(for example [1,0,2,0] client needs  1 1-core, 0 2-core, 2 7-core and 0 11-core VMs) 
    
    public Client(int aVMs,float aprice){//initialization
        VMs = aVMs;
        price = aprice;
        vms = new int[4];
    }
    

    public int getVMs(){//return the VMs that client wants
        return VMs;
    }
    
    public float getPrice(){//return the price that client offers
        return price;
    }
    
    public void setVMs(int aVMs){//set client's VMs
        VMs = aVMs;
    }
    
    public void setPrice(float aprice){//set client's price
        price  = aprice;
    }

}
