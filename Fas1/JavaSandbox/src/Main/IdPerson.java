package Main;

public class IdPerson<Id> {
	private Id id;
	private String name;
	
	 
	  public  IdPerson(Id identification,String myName) {  
	    id = identification;
	    name = myName;   
	  }
	  
	 
	  
	  public Id getid() {
	    return id;
	  }
	 
	  
	  
	  public String getname() {
	    return name;
	  }
	 
	  public String toString() { 
	    return "(" + id + ", " + name + ")";  
	  }
	 }
	  

