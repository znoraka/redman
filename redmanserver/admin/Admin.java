package admin;

import java.net.Socket;
import java.util.concurrent.ExecutorService;

import server.Client;
import slave.SlaveManager;

public class Admin extends Client{

	boolean login;
	String password;

	public Admin(Socket sock, ExecutorService es) {
		super(sock, es);
		login = false;
		password = "àyx.k'q";
	}

	@Override
	public void onMessage(String s) {
		//System.out.println("[admin] : " + s + ".");
		if(s == null) {
			cl.stop();
			login = false;
		} else {
			if(!login) {
				if(s.equals(password)) {
					login = true;
					acceptLogin();
				} else {
					refuseLogin();
				}
			} else {
				int index = s.indexOf(":");
				String cmd = s.substring(index + 1, s.length());
				index = Integer.parseInt(s.substring(0, index));
				//System.out.println("cmd : " + cmd);
				//System.out.println("for client : " + index);
				SlaveManager.getInstance().sendToClient(index, cmd);
			}
		}

	}

	public void sendSlavesList(String s) {
		if(login)
			send("AC"+s);
	}

	public void addClient(String name) {
		if(login)
			send("NC:"+name);
	}

	public void removeClient(int index) {
		if(login) {
			System.out.println("sending dc");
			send("DC:"+index);
		}
	}

	public void displayCommandOutput(int index, String s) {
		if(login)
			send("CM:"+index+";"+s);
	}
	
	public void acceptLogin() {
		System.out.println("login accepted!");
		send("true");
		SlaveManager.getInstance().sendAllClients();
	}
	
	public void refuseLogin() {
		System.out.println("login refused!");
		send("false");
	}
}
