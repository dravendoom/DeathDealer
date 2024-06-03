### **PROJECT DEATHDEALER**
![Example Image](githubImages/TitleImage.png)

## Description

The concept behind Project Deathdealer (a placeholder name) is to create a vampire survivor-like game with unique twists. I drew inspiration from a game called Median XL, a Diablo II mod that introduces challenging static boss content for solo players. This mod features specific character-altering attributes (e.g., changing ability functionalities) and custom loot tables. 
Typically, vampire survivor games focus on wave-based content with occasional bosses appearing after certain milestones, usually based on time. Project Deathdealer aims to innovate by offering an open-world experience where players can explore and, once they are strong enough, enter unique biome areas to challenge bosses. This approach effectively creates a hybrid genre, blending open-world exploration with the traditional vampire survivor mechanics.
## Features

- Unique mob types and wave sequences.
- 8 Different abilities all made with unique scaling in mind. (5 currently with VFX).
- Item drops with different raritys.

## Future Features
- Boss arenas that you can enter at will when you feel you are up to the challange.
- UI for the inventory system and item aquisition.
- New characters and enemy mob types.

## Portfolio Blueprint Review

Almost 85-90% of the project was done via blueprints and other unreal uassets. I will be going over most of the core fundamental blueprints that comprise of the game. There is also source C++ code that is generally used for custom structs and struct functionalties. 

## BLUEPRINT: BP_DefaultCharacter

This blueprint represents the player's character. Here we will be going over all the movement functionalities and animations + other getter/setter methods.

![Example Image](githubImages/playercharacter/Movement.png)

The blueprint below is for setting flip book animations based on the movement speed of the player at the current tick in time.

![Example Image](githubImages/playercharacter/MovementAnimations.png)

![Example Image](githubImages/playercharacter/PlayerLevelup.png)

![Example Image](githubImages/playercharacter/DamageEvent.png)

![Example Image](githubImages/playercharacter/AddPlayerStats.png)

## BLUEPRINT: BP_BaseEnemy

This blueprint represents a simple enemy type that uses the moveTo default AI operation and an attack function to hit the player when reaching a close proximity. 

![Example Image](githubImages/enemy/AttackEventEnemy.png)

![Example Image](githubImages/enemy/BTTAttack.png)

![Example Image](githubImages/enemy/EnemyAI.png)

![Example Image](githubImages/enemy/EnemyOrient.png)

![Example Image](githubImages/enemy/EnemyTakeDamage.png)

## BLUEPRINT: BP_DeathDealer

This blueprint represents the gamemode, and is reponsible for level up triggers, item triggers and spawning monster waves.

![Example Image](githubImages/gamemode/BreakWaveStruct.png)

![Example Image](githubImages/gamemode/EnemyWaveSystem.png)

![Example Image](githubImages/gamemode/GameModeStart.png)

![Example Image](githubImages/gamemode/RandomEnemySpawn.png)

![Example Image](githubImages/gamemode/SelectAbilityOrPassive.png)

![Example Image](githubImages/gamemode/WaveDecrementor.png)

## BLUEPRINT: Spells_Folder

These images will represent some of the spells that are currently implemented in the game. Some of these still need hookups to gather play stats but in total work. (5 out of 8) of the current spells have VFX.

![Example Image](githubImages/Spells/FireBlast.png)

![Example Image](githubImages/Spells/FlameFrontStart.png)

![Example Image](githubImages/Spells/GetHitResult.png)

![Example Image](githubImages/Spells/MultiProjectile.png)

![Example Image](githubImages/Spells/ChainLightning/ChainLightningBase.png)

![Example Image](githubImages/Spells/ChainLightning/ChainLightning.png)

## BLUEPRINT: Spells_Passive_UI

These blueprint images are responsible for the UI to select spells or passives based on the players current level.

![Example Image](githubImages/SpellLevelUI/Buttons.png)

![Example Image](githubImages/SpellLevelUI/SpellButtons.png)

![Example Image](githubImages/SpellLevelUI/MasterUI.png)

## BLUEPRINT (Still in the works): Items

THese blueprints and data tables are used in conjunction with C++ code to develop an item system. Items will first select rarity based on weights, then select an item from that rarity. These item names are then used to gather info from the Data Table and are served to the player, which then uses AddStat nodes based on the item equipped.

![Example Image](githubImages/Items/IItemdatatable.png)

![Example Image](githubImages/Items/ItemExample.png)

## Few Util functions for calculations

![Example Image](githubImages/UtilFunctions/Damage.png)

![Example Image](githubImages/UtilFunctions/DamageReduc.png)


