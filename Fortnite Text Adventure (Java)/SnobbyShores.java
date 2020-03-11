
public class SnobbyShores extends Locations {
	Weapon loot;
	// Prints out the location name of where the user chose to land
	public void land () {
		System.out.println("YOU HAVE LANDED IN SNOBBY SHORES!");
		}
		
	/*When loot is found, this method will be called to choose what type of loot there is
	 * The type of loot chosen and probability of a certain item is different depending on the chosen locaton
	 */
	public void loot() {
		int weaponRandom;
		weaponRandom = random(1, 100);
		if (weaponRandom >= 70) {
			System.out.println("You found a Shotgun!");
			loot = Shotgun;
		}
		if (weaponRandom < 69 && weaponRandom >= 40) {
			System.out.println("You found an AR");
			loot = AR;
		}
		if (weaponRandom < 39  && weaponRandom >= 35) {
			System.out.println("You found a Pistol");
			loot = Pistol;
		}
		if (weaponRandom < 34 && weaponRandom >= 10) {
			System.out.println("You found a Shield Potion");
			loot = Shield;
		}
		if (weaponRandom < 9 && weaponRandom >= 1) {
			System.out.println("You found a MedKit");
			loot = MedKit;
		}
	}
	public Weapon getLoot() {
		return loot;
	}
		
	// Method to generate random number between certain parameters
	public int random(int min, int max) {
		int range = (max - min) + 1;
		return(int)(Math.random()*range) + min;
	}	

}
