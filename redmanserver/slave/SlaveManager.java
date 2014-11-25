package slave;

import java.util.ArrayList;

import admin.Admin;

public class SlaveManager {
	private ArrayList<Slave> clients;
	private static SlaveManager instance;
	private Admin admin;
	
	public static SlaveManager getInstance() {
		if(instance == null) {
			instance = new SlaveManager();
		}
		return instance;
	}
	
	private SlaveManager() {
		clients = new ArrayList<Slave>();
	}
	
	public void addClient(Slave client) {
		clients.add(client);
	}
	
	public void notifyNewClient(Slave client) {
		System.out.println("new client with name : " + client.getName());
		if(admin != null) {
			admin.addClient(client.getName());
		}
	}
	
	public void notifyRemoveClient(Slave client) {
		if(admin != null) {
			admin.removeClient(clients.indexOf(client));
		}
	}
	
	public void removeClient(Slave client) {
		System.out.println("client : " + clients.indexOf(client) + " removed");
		notifyRemoveClient(client);
		clients.remove(client);
	}
	
	public void displayOutput(Slave client, String s) {
		if(admin != null) {
			admin.displayCommandOutput(clients.indexOf(client), s);
		}
	}
	
	public void sendAllClients() {
		if(admin != null) {
			for (Slave slave : clients) {
				admin.addClient(slave.getName());
			}
		}
	}
	
	public boolean canAddClient() {
		return true;
	}
	
	public void setAdmin(Admin admin) {
		this.admin = admin;
	}
	
	public void sendToClient(int index, String msg) {
		clients.get(index).send(msg);
	}
}
