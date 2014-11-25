package slave;

import java.net.Socket;
import java.util.concurrent.ExecutorService;

import server.Client;

public class Slave extends Client{
	private String name = null;
	
	
	public Slave (Socket sock, ExecutorService es) {
		super(sock, es);
		this.sock = sock;
		
	}
	
	public void setName(String name) {
		this.name = name;
		SlaveManager.getInstance().notifyNewClient(this);
	}
	
	public void exec(String cmd) {
		
	}

	public String export() {
		return name;
	}

	@Override
	public void onMessage(String s) {
		if(name == null) {
			setName(s);
		}
		
		if(s == null) {
			SlaveManager.getInstance().removeClient(this);
			cl.stop();
		}
		else {
			SlaveManager.getInstance().displayOutput(this, s);
		}
	}

	public String getName() {
		return this.name;
	}
}
