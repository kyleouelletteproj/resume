import java.util.Scanner;

public class Game {

	public static void main(String[] args) {
		
		//Variables initialized
		boolean finalFight = false;
		int killCount = 0;
		int playersLeft = 40;
		String playerLocation = null;
		boolean playerWon = false;
		int playerResponse;
		boolean inGame = false;;
		boolean inFight = false;
		
		//Add Weapons
		Weapon AR = new Weapon(37);
		Weapon Shotgun = new Weapon(100);
		Weapon Pistol = new Weapon(23);
		Weapon Shield = new Weapon(50);
		Weapon MedKit = new Weapon(100);
		Weapon PickAxe = new Weapon(10);
		
		//Create Locations
		RetailRow retail = new RetailRow();
		PleasantPark pleasant = new PleasantPark();
		TiltedTowers tilted = new TiltedTowers();
		SnobbyShores snobby = new SnobbyShores();
		
		//Create player and enemy
		Player player = new Player(100,50, PickAxe);
		Enemy enemy = new Enemy(100, 0, AR);
		enemy.enemyReset();
		
		Scanner response = new Scanner(System.in);
		
		//Landing and looting
		System.out.println("Where do you want to land? \n1. Retail Row \n2. Snobby Shores"
				+ "\n3. Tilted Towers\n4. Pleasant Park");
		
		//Land at Retail
		int locationResponse = response.nextInt();
		if(locationResponse == 1) {
			playerLocation = "retail";
			System.out.println("You land at Retail Row.\n1. Loot House\n2. Run Outside");
			playersLeft--;
			playerResponse = response.nextInt();
			if (playerResponse == 1) {
				inGame = true;
				retail.loot();
				player.setGun(retail.getLoot());
				if(retail.getLoot() == MedKit && player.getHealth() < 100) {
					System.out.println("You found a Med Kit and used it.");
					player.setHealth(100);
				} else {
					System.out.println("You already have full health.");
				}
			if(playerResponse == 2) {
				System.out.println("You run outside and die.");
				inGame = false;
			}
		}
		}
		
		//Land at Snobby
		if(locationResponse == 2) {
			playerLocation = "snobby";
			System.out.println("You land at Snobby Shores. \n1. Loot House\n2. Run Outside");
			playerResponse = response.nextInt();
			if (playerResponse == 1) {
				inGame = true;
				snobby.loot();
				player.setGun(snobby.getLoot());
				if(snobby.getLoot() == MedKit && player.getHealth() < 100) {
					System.out.println("You found a Med Kit and used it.");
					player.setHealth(100);
				} else {
					System.out.println("You already have full health.");
				}
			if(playerResponse == 2) {
				System.out.println("You run outside and die.");
				inGame = false;
			}
		}
		}
		
		//Landed at Tilted
		if(locationResponse == 3) {
			playerLocation = "tilted";
			System.out.println("You land at Tilted Towers. \n1. Loot House\n2. Run Outside");
			playerResponse = response.nextInt();
			if (playerResponse == 1) {
				inGame = true;
				tilted.loot();
				player.setGun(tilted.getLoot());
				if(tilted.getLoot() == MedKit && player.getHealth() < 100) {
					System.out.println("You found a Med Kit and used it.\n");
					player.setHealth(100);
				} else {
					System.out.println("You already have full health.");
				}
			if(playerResponse == 2) {
				System.out.println("You run outside and die.\n");
				inGame = false;
			}
		}
		}
		
		//Land at Pleasant
		if(locationResponse == 4) {
			playerLocation = "pleasant";
			System.out.println("You land at Pleasant Park. \n1. Loot House\n2. Run Outside\n");
			playerResponse = response.nextInt();
			if (playerResponse == 1) {
				inGame = true;
				pleasant.loot();
				player.setGun(pleasant.getLoot());
				if(pleasant.getLoot() == MedKit && player.getHealth() < 100) {
					System.out.println("You found a Med Kit and used it.\n");
					player.setHealth(100);
				} else {
					System.out.println("You already have full health.\n");
				}
			if(playerResponse == 2) {
				System.out.println("You run outside and die.\n");
				inGame = false;
			}
		}
		}
		
		//Main Game Loop
		while(inGame == true) {
			int nextAction = random(1,100);
			if(nextAction < 20) {
				System.out.println("You see a player in the distance. \n1. Fight\n2. Avoid him\n");
				if(response.nextInt() == 1) {
					inFight = true;
				} else {
					//Blank to continue game
				}
				
			}
			if(nextAction > 90 && nextAction < 100) {
				System.out.println("You see another chest\n1. Loot\n2. Continue searching\n");
				playerResponse = response.nextInt();
				if(playerResponse == 1) {
					if(playerLocation.equals("tilted")) {
						tilted.loot();
					}
					if(playerLocation.equals("retail")) {
						retail.loot();
					}
					if(playerLocation.equals("snobby")) {
						snobby.loot();
					}
					if(playerLocation.equals("pleasant")) {
						snobby.loot();
					} else {
						//Blank to continue
					}
				} 
				
				//Special Ninja Event
				if(nextAction == 100) {
					ninjaEvent(player);
				}
				//Running toward storm makes the game go by
			} else {
				System.out.println("You run toward the storm.");
				playersLeft--;
			}
			
			//Fight Algorithm
		while(inFight == true) {
			System.out.println();
			if(enemy.getDistance() <= 15) {
				
			} else {
				Shotgun.setDamage(Shotgun.getDamage() / enemy.getDistance());
			}
		System.out.println("\nEnemy Distance: "+enemy.getDistance());
		System.out.println("1. Shoot");
		System.out.println("2. Build");
		System.out.println("3. Run\n");
		int choice = response.nextInt();
		if(choice == 1) {
			//Check if player shot hit
			player.shoot(enemy);
			if(enemy.getHealth() <= 0) {
				System.out.println("You have killed your enemy.");
				System.out.println();
				killCount++;
				inGame = false;
				break;
			}
			enemy.shoot(player);
			//Check if enemy shot hit
			if(player.getPlayerShotHit() == true) {
				enemy.takeDamage(player.getGun().getDamage());
				player.setPlayerShotHit(false);
			}
			if(enemy.getEnemyShotHit() == true) {
				if (enemy.getGun() == AR) {
					player.takeDamage(AR.getDamage());
					enemy.setEnemyShotHit(false);
				}
				if (enemy.getGun() == Shotgun) {
					player.takeDamage(Shotgun.getDamage());
					enemy.setEnemyShotHit(false);
				}
				if (enemy.getGun() == Pistol) {
					player.takeDamage(Pistol.getDamage());
					enemy.setEnemyShotHit(false);
				}
			}
			System.out.println("You have "+player.getHealth()+" health and "+player.getShield()+" shield.");
		}
		if(choice == 2) {
			System.out.println("You build a base to protect you");
		}
		if(choice == 3) {
			System.out.println("You run away from the fight.");
			inFight = false;
			break;
		}
		}
		if(playersLeft <= 2) {
			finalFight = true;
		}
		
		//Final Fight
		while(finalFight == true) {
			System.out.println("Final Fight!");
			if(enemy.getDistance() <= 15) {	
			} else {
				Shotgun.setDamage(Shotgun.getDamage() / enemy.getDistance());
			}
		System.out.println("\nEnemy Distance: "+enemy.getDistance());
		System.out.println("1. Shoot");
		System.out.println("2. Build");
		int choice = response.nextInt();
		if(choice == 1) {
			player.shoot(enemy);
			enemy.shoot(player);
			//Check if enemy and player shot hit
			if(player.getPlayerShotHit() == true) {
				enemy.takeDamage(player.getGun().getDamage());
				player.setPlayerShotHit(false);
		}
			if(enemy.getHealth() <= 0) {
				finalFight = false;
				inGame = false;
				killCount++;
				playerWon = true;
				break;
			}
			if(enemy.getEnemyShotHit() == true) {
				if (enemy.getGun() == AR) {
					player.takeDamage(AR.getDamage());
					enemy.setEnemyShotHit(false);
				}
				if (enemy.getGun() == Shotgun) {
					player.takeDamage(Shotgun.getDamage());
					enemy.setEnemyShotHit(false);
				}
				if (enemy.getGun() == Pistol) {
					player.takeDamage(Pistol.getDamage());
					enemy.setEnemyShotHit(false);
				}
				if(player.getHealth() <= 0) {
					finalFight = false;;
					inGame = false;
					killCount++;
					playerWon = true;
					break;
				}
			}
			System.out.println("You have "+player.getHealth()+" health and "+player.getShield()+" shield.");
		}
		if(choice == 2) {
			System.out.println("You build a base to protect you");
		}
		}
			}
		endGame(playerWon, killCount, playersLeft);
	}
	
	public static int random(int min, int max) {
		int range = (max - min) + 1;
		return(int)(Math.random()*range) + min;
	}
	//end Game
	public static void endGame(boolean checkWin,int kills, int left) {
		if(checkWin == true) {
		System.out.println("Victory Royale!\nKills: "+kills);
		} else {
			System.out.println("You have died.\nKills: "+kills);
			System.out.println("Place: "+left);
		}
	}
	//Ninja Event
	public static void ninjaEvent(Player x) {
		System.out.println("You found Ninja! He is after you!");
		Weapon NinjaShotty = new Weapon(100);
		Enemy ninja = new Enemy(100, 100, NinjaShotty);
		int fate = random(0,5);
		if(fate == 0) {
			Scanner response = new Scanner(System.in);
			System.out.println("Ninja builds up and gets high ground");
			System.out.println("1. Try to build up");
			System.out.println("2. Take me to the lobby");
			int respond = response.nextInt();
			if(respond == 1) {
				if(random(1,50) == 1) {
					System.out.println("You were able to build up and kill Ninja.");
				} else {
					System.out.println("Ninja has defeated you. Better luck next time.");
					x.setHealth(0);
					x.setShield(0);
				}
			}
		}
		if(fate < 5 && fate > 0) {
			System.out.println("Ninja uses an impulse grenade to headshot you.");
			x.setHealth(0);
			x.setShield(0);
		}
		if(fate == 5) {
			System.out.println("Ninja flees.");
		}
	}
}
