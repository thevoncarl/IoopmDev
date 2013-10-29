/**
 * 
 */
package Main;

/**
 * @author MaxN
 *
 */

abstract public class Bilar implements Cloneable  {
	private String motor; 

	Bilar(String motor){
		this.motor = motor;
	}


	public String GetMotor(){return motor;}

	public void SetMotor(String newMotor){
		motor = newMotor;
	}

	abstract String bilTyp();

	protected Bilar clone(){
		try {
			return (Bilar)super.clone();
		} catch (CloneNotSupportedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return null;
		}

	}
}
