import java.security.SecureRandom;
import java.util.Arrays;

public class encryption{
	
	
	private String secretStr = "hey";
	 byte[] encoded;
	 byte[] decoded;
	 byte[] key;
	 byte[] secret;
	
	public encryption(String pass){
		
	    		this.secret = pass.getBytes();
	    	    this.encoded = new byte[secret.length];
	    	    this.decoded = new byte[secret.length];

	    	    // Generate random key (has to be exchanged)
	    	    this.key = new byte[secret.length];
	    	    new SecureRandom().nextBytes(key);
	    	    
	    	    // Encrypt
	    	    for (int i = 0; i < this.secret.length; i++) {
	    	        encoded[i] = (byte) (this.secret[i] ^ this.key[i]);
	    	    }

	}
	
	public String getEncoded(){
		
		return new String(encoded);
		
	}

	public String getDecoded(){
		
		return new String(decoded);
		
	} 

	public byte[] decrypt(){
    for (int i = 0; i < encoded.length; i++) {
        this.decoded[i] = (byte) (this.encoded[i] ^ this.key[i]);
    }
    
    return this.decoded;
    
	}
}