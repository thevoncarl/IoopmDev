package Main;

class Ford extends Bilar{

	Ford(String motor){
		super("Fords: " + motor);
	}

	String bilTyp(){ return  "Ford fråm klassen! Med en " + this.GetMotor() + " motor"; } 
}