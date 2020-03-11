
public class RetailRow extends Locations {
	Weapon loot = PickAxe;
	private int weaponRandom;
	// Prints out the location name of where the user chose to land
	public void land () {
		System.out.println("YOU HAVE LANDED IN RETAIL ROW!");
	}
		
	/*When loot is found, this method will be called to choose what type of loot there is
	 * The type of loot chosen and probability of a certain item is different depending on the chosen locaton		
	 */
	/*
	 * 1. AR
	 * 2. Shotgun
	 * 3. Pistol
	 * 4. Shield (50)
	 * 5. Med Kits
	 */
	public void loot() {
		weaponRandom = random(1, 100);
		if (weaponRandom >= 80) {				
			System.out.println("You found a Shotgun!");
			loot = Shotgun;
		}
		if (weaponRandom < 79 && weaponRandom >= 60) {
			System.out.println("You found an AR");
			loot = AR;
		}
		if (weaponRandom < 59  && weaponRandom >= 40) {
			System.out.println("You found a Pistol");
			loot = Pistol;
		}
		if (weaponRandom < 39 && weaponRandom >= 30) {
			System.out.println("You found a Shield Potion");
		}
		if (weaponRandom < 29 && weaponRandom >= 1) {
			System.out.println("You found a MedKit");
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
