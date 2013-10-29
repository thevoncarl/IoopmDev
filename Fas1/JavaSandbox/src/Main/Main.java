package Main;



	class MaxBil extends Audi{
	
	MaxBil(){
		super("V8");
	}
	String bilTyp (){
		return super.bilTyp() + " Fast detta �r max bil!";
	}
}







public class Main {

	public static class Garage implements Cloneable {
		int carCount;
		private Bilar[] garageBilar;

		Garage(Bilar[] GarageBilar ){
			garageBilar = GarageBilar;
			carCount = garageBilar.length;
		}

		public Bilar GetCar(int index){

			return garageBilar[index];
		}


		protected Garage clone(){
			Garage copy = null;
			try {
				copy = (Garage)super.clone();
			} catch (CloneNotSupportedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			copy.garageBilar = garageBilar.clone();
			for (int index = 0; index < garageBilar.length; index++){
				copy.garageBilar[index] = garageBilar[index].clone();
			}

			return copy;

		}


	}




	private static void write (Bilar a){
		System.out.println(a.bilTyp());
	}

	private static boolean EqualObj (Object A, Object B){

		return A.equals(B);
	}

	private static boolean  StruktuelltLikaObj (Object A, Object B){

		return  A.getClass() == B.getClass() ;


	}
	public static void main(String[] args){

		Audi Bil1 = new Audi("K�rring");
		Ford Bil2 = new Ford("T�nt");
		Bilar Bil3 = new MaxBil();

		Bilar[] GarageBilar = {Bil1,Bil2,Bil3};

		Garage garaget = new Garage(GarageBilar);
		Garage garaget2 = garaget.clone();

		write(garaget.GetCar(0));
		write(garaget2.GetCar(0));

		System.out.println("EqualOBJ:" + EqualObj(garaget,garaget2));
		System.out.println("StrukturelltLika:" + StruktuelltLikaObj(garaget,garaget2));

		garaget2.GetCar(0).SetMotor("Smutt");

		write(garaget.GetCar(0));
		write(garaget2.GetCar(0));

		/*
	write (Bil1);
	write (Bil2);
	write (Bil3);

	IdPerson<String> Viktor = new IdPerson<String>("Cooling","Viktor");
	IdPerson<Integer> Max = new IdPerson<Integer>(12,"Max");

	String hej = Viktor.getid();
	int hej2 = Max.getid();

	System.out.println("Id: " + hej +" Namn: " +Viktor.getname() +" \n " + " Id2: " +hej2 + " Namn2: " +Max.getname());
		 */

	}
}


