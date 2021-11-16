/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package TSimple;

/**
 *
 * @author lap14784
 */
import java.util.logging.Level;
import java.util.logging.Logger;
import org.apache.thrift.TException;

public class MultiplicationHandler implements MultiplicationService.Iface {

	@Override
	 public int multiply(int n1, int n2) throws TException {
	    System.out.println("Multiply(" + n1 + "," + n2 + ")");
            try {
                Thread.sleep(500);
            } catch (InterruptedException ex) {
                Logger.getLogger(MultiplicationHandler.class.getName()).log(Level.SEVERE, null, ex);
            }
	    return n1 * n2;
	 }

	
}