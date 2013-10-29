package MainTest;
import static org.junit.Assert.*;

import org.junit.Test;

import Main.IdPerson;

/**
 * @author MaxN <a href="www.facebook.com/MaxN">Max Andersson</a>	
 *
 */
public class IdPersonTest {
	
	
	/**
	 * Test method for {@link IdPerson#getid()}.
	 */
	@Test
	public final void testGetid() {
		IdPerson<String> Viktor = new IdPerson<String>("Cooling","Viktor");
		IdPerson<Integer> Max = new IdPerson<Integer>(12,"Max");
		
		assertEquals("String dont work with Parametric Polymorph...", Viktor.getid() ,"Cooling" );
		assertEquals("Integer dont work with Parametric Polymorph...",Max.getid(), Integer.valueOf(12) );
		
	}
}