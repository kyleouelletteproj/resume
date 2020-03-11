public class Enemy extends Player {
	private boolean enemyShotHit = false;
	private int distance;
	private Weapon Gun;
	public Enemy(int hp, int shld, Weapon gun) {
		super(hp, shld,gun);
		Gun = gun;
	}
	public void enemyReset() {
		setHealth(random(20,100));
		setShield(random(0,100));
		distance = random(1,200);
	}
	public void shoot(Player x) {
		if(random(1,100) >= 50) {
			System.out.println("Your enemy hit you for "+Gun.getDamage()+" damage.");
			enemyShotHit = true;
	} else {
		System.out.println("Your enemy missed their shot.");
	}
	}
	public void takeDamage(int dmg) {
		if(getShield() > dmg) {
		setShield(getShield()-dmg);	
		} else {
			dmg -= getShield();
			setShield(0);
			 setHealth(getHealth()-dmg);
		}
	}
	public void setEnemyShotHit(boolean x) {
		enemyShotHit = x;
	}
	public boolean getEnemyShotHit() {
		return enemyShotHit;
	}
	public int getDistance() {
		return distance;
	}
	public void setDistance(int x) {
		distance = x;
	}
}
