public class Weapon {
	private int type;
	private int damage;
	private String name;
	/*
	 * 1. AR
	 * 2. Shotgun
	 * 3. Pistol
	 * 4. Shield (50)
	 * 5. Med Kits
	 */
	public Weapon(int dmg) {
		damage = dmg;
	}
	public void setDamage(int dmg) {
		damage = dmg;
	}
	public int getDamage() {
		return damage;
	}
	public int getType() {
		return type;
	}
	public void setType(int id) {
		type = id;
	}
}
