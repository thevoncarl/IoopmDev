package Main;

class Ford extends Bilar{

	Ford(String motor){
		super("Fords: " + motor);
	}

	String bilTyp(){ return  "Ford fr�m klassen! Med en " + this.GetMotor() + " motor"; } 
}