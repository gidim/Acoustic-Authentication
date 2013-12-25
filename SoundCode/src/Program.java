import java.util.ArrayList;

import javax.sound.sampled.LineUnavailableException;


public class Program {

	public static void main(String[] args) throws 
	LineUnavailableException {
		final int hz = 4000; 
		final int length = 50;
		
		
		final double beepVol = 1;
		final double toneSepVol = 0.01;
		final double NumSepVol = 0.5;
		
		//set class constants
		Tone.SAMPLE_RATE = 20000f;
		Tone.setMsecs(length);
		Tone.setHz(hz);
		ToneSeperator.msecs = length*5;
		NumberSeperator.msecs = length * 10;
		//Tone.setVol(1);
		
		
		
		//generate password
		String pass = "637241";

		//beeps array
		ArrayList<Bit> beeps = new ArrayList<Bit>();
		
		
		//generate beeps for each number
		for (int i = 0; i< pass.length() ; i++) {
			
			char c = pass.charAt(i);
			int numValue = Character.getNumericValue(c);
			System.out.println(numValue);
			
			//add a tone with seperators
			for(int j = 0  ; j < (numValue) ; j++  ){
				
				beeps.add(new Tone(beepVol));
				
				beeps.add(new ToneSeperator(toneSepVol));	
			}
			
			//add number seperator
			if(i != (pass.length() -1)) //this isnt the last num
			beeps.add(new NumberSeperator(NumSepVol));
			
		}
		
		for (int i = 0; i< beeps.size() ; i++) {
			
			beeps.get(i).play();
			
		}
		

		
        

}
}
	


