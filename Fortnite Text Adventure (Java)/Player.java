public class Player {
	private int health;
	private int shield;
	private Weapon Gun;
	private boolean playerShotHit;
	private boolean baseBuilt;
	private int kills;
	
	private int[] inventory = new int[] {0, 0, 0, 0, 0};
	/*
	 *  int[0] = Shotgun
	 *  int[1] = AR
	 *  int[2] = Pistol
	 *  int[3] = Shield
	 *  int[4] = MedKit
	 *  
	 *  If the int corresponding to the item is 0, the user does not have that item in their inventory
	 *  If the int is 1, then the user does have the item in their inventory
	 */
	
	public Player(int hp, int shld, Weapon gun) {
		health = hp;
		shield = shld;
		Gun = gun;
	}
	//Inventory for player 
	
	
	public void shoot(Player x) {
		if(random(1,100) >= 50) {
			System.out.println("You have dealt "+Gun.getDamage()+" damage to your opponent.");
			playerShotHit = true;
		} else {
			System.out.println("You missed your shot.");
		}
	}
	public void takeDamage(int dmg) {
		if(shield > dmg) {
		shield -= dmg;	
		} else {
			dmg -= shield;
			shield = 0;
			health -= dmg;
		}
		if(health < 0) {
			health = 0;
		}
	}
	public void setHealth(int hp) {
		health = hp;
	}
	public void setShield(int shld) {
		shield = shld;
	}
	public int getHealth() {
		return health;
	}
	public int getShield() {
		return shield;
	}
	public int random(int min, int max) {
		int range = (max - min) + 1;
		return(int)(Math.random()*range) + min;
	}
	public void setPlayerShotHit(boolean x) {
		playerShotHit = x;
	}
	public boolean getPlayerShotHit() {
		return playerShotHit;
	}
	public Weapon getGun() {
		return Gun;
	}
	public boolean getBaseBuilt() {
		return baseBuilt;
	}
	public void setGun(Weapon x) {
		Gun = x;
	}
	public void setBaseBuilt(boolean x) {
		baseBuilt = x;
	}
	public int[] getInventory() {
		return inventory;
	}
	public void setInventory(int p, int num) {
		inventory[p] = num;
	}
	public void addKill() {
		kills += 1;
	}
	public int getKills() {
		return kills;
	}
}
