package Main;

class Audi extends Bilar{
	Audi(String motor){
		super("Audis: " + motor);
	}
	Audi(String motor, String motorSerie){
		super("Audis: " + motor +  "in the" + motorSerie + " sereies")  ;
	}
	String bilTyp(){return "Audi fr�n klassen! Med en " + this.GetMotor() + " motor"; }
}